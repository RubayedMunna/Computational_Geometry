#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Point 
{
    ll x,y;
};
Point p0;
Point reference;
stack<Point>stk;
vector<Point>P;
ll n;
vector<Point>CH;

ll crossProduct(Point p1,Point p2,Point p3)
{
    return ((p2.x-p1.x)*(p3.y-p1.y))-((p2.y-p1.y)*(p3.x-p1.x));
}

ll dotProduct(Point p1,Point p2,Point p3)
{
    return ((p2.x-p1.x)*(p3.x-p1.x))+((p2.y-p1.y)*(p3.y-p1.y));
}

ll CCW(Point p1,Point p2, Point p3)
{
    return crossProduct(p1,p2,p3);
}

double get_dist(Point p1,Point p2)
{
    double dist_x=p1.x-p2.x;
    double dist_y=p1.y-p2.y;
    double dist=sqrt(dist_x*dist_x+dist_y*dist_y);
    return dist;
}

ll get_bottom_most_point()
{
    ll idx=0;
    Point bottom=P[0];
    for(ll i=0;i<n;i++)
    {
        if(P[i].x<bottom.x||(P[i].x==bottom.x&&P[i].y<bottom.y))
        {
            bottom=P[i];
            idx=i;
        }
    }
    return idx;
}
bool comp(Point p1,Point p2)
{
    if(CCW(p0,p1,p2)>0)
    {
        return true;
    }
    if(CCW(p0,p1,p2)<0)
    {
        return false;
    }
    if(CCW(p0,p1,p2)==0)
    {
        if(get_dist(p0,p1)<get_dist(p0,p2))
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}

void remove_colinear_points()
{
    vector<Point> v;
    for(ll i=1;i<=n-2;i++)
    {
        if(CCW(reference,P[i],P[i+1])==0)
        {
            P[i].x=LLONG_MAX;
            P[i].y=LLONG_MAX;
        }
    }
    
    for(ll i=0;i<P.size();i++)
    {
        if(P[i].x!=LLONG_MAX&&P[i].y!=LLONG_MAX)
        {
            v.push_back(P[i]);
        }
        
    }
    P.clear();
    ll siz=v.size();
    for(ll i=0;i<siz;i++)
    {
        P.push_back(v[i]);
    }
}


void graham_scan_CH()
{
    ll b_index=get_bottom_most_point();
    swap(P[0],P[b_index]);
    reference=P[0];
    sort(P.begin(),P.end(),comp);
    cout<<"After Sorting: "<<N;
    for(auto it: P)
    {
        cout<<it.x<<" "<<it.y<<N;
    }
    remove_colinear_points();
    cout<<"After Removing"<<N;
    for(auto it: P )
    {
        cout<<it.x<<" "<<it.y<<N;
    }

    n=P.size();
    while(!stk.empty())
    {
        stk.pop();
    }
    stk.push(P[0]);
    stk.push(P[1]);

    for(ll i=2;i<n;i++)
    {
        Point top=stk.top();
        stk.pop();
        Point next_to_top=stk.top();
        stk.pop();

        while(CCW(next_to_top,top,P[i])<=0)
        {
            top=next_to_top;
            next_to_top=stk.top();
            stk.pop();
        }
        stk.push(next_to_top);
        stk.push(top);
        stk.push(P[i]);
    }
    CH.clear();
    while(!stk.empty())
    {
        CH.push_back(stk.top());
        stk.pop();
    }
    reverse(CH.begin(),CH.end());
} 
int main()
{
    ll n;
    cin>>n;
    P.clear();
    for(ll i=0;i<n;i++)
    {
        Point PP;
        cin>>PP.x>>PP.y;
        P.push_back(PP);
    }
    // for(ll i=0; i<n; i++)
    // {
    //     cout<<P[i].x<<" "<<P[i].y<<N;
    // }
    
    graham_scan_CH();
    cout<<"Convex Hull: "<<N;
    for(ll i=0;i<CH.size();i++)
    {
        cout<<CH[i].x<<" "<<CH[i].y<<N;
    }

    return 0;
}