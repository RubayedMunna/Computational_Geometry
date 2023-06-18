#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
struct Point 
{
    ll x,y;
};

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

int main()
{
    Point p1,p2,p3;
    cout<<"Enter Three Points: "<<N;

    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;

    if(CCW(p1,p2,p3)>0)
    {
        cout<<"P3 is in counter Clockwise orientation with respect to p1 and p2"<<N;
    }
    else if(CCW(p1,p2,p3)<0)
    {
        cout<<"P3 is in clockwise orientation with respect to P1 and P2"<<N;
    }
    else 
    {
        cout<<"P1, P2 and P3 are colinear Points"<<N;
    }
    return 0;
}
