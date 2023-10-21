#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> point;

bool segmentIntersect(point p0,point p1,point p2,point p3);
int direction(point p0,point p1,point p2);
bool onSegment(point p0,point p1,point p2);

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    

    point p0,p1,p2,p3;

    int x,y;

    cin>>x>>y; p0={x,y};
    cin>>x>>y; p1={x,y};
    cin>>x>>y; p2={x,y};
    cin>>x>>y; p3={x,y};

    if(segmentIntersect(p0,p1,p2,p3)){
        cout<<"Line Segments Intersects"<<endl;;
    }else{
        cout<<"Line Segments do not Intersects"<<endl;
    }



    return 0;
}

bool segmentIntersect(point p0,point p1,point p2,point p3)
{
    int d0,d1,d2,d3;
    d0= direction(p2,p3,p0);
    d1= direction(p2,p3,p1);
    d2= direction(p0,p1,p2);
    d3= direction(p0,p2,p3);

    if(((d0>0 and d1<0) or (d0<0 and d1>0)) and ((d2>0 and d3<0) or (d2<0 and d3>0))){
        return true;
    }
    else if(d0==0 and onSegment(p2,p3,p0)) return true;
    else if(d1==0 and onSegment(p2,p3,p1)) return true;
    else if(d2==0 and onSegment(p0,p1,p2)) return true;
    else if(d3==0 and onSegment(p0,p1,p3)) return true;
    else return false;
}

int direction(point p0,point p1,point p2)
{   
    //(p1-p0)*(p2-p0)
    int crossProduct=((p1.first-p0.first)*(p2.second-p0.second))-((p2.first-p0.first)*(p1.second-p0.second));
    return crossProduct;
}

bool onSegment(point p0,point p1,point p2)
{
    bool part1=(p2.first>= min(p0.first,p1.first)) and (p2.first<= max(p0.first,p1.first));
    bool part2=(p2.second>= min(p0.second,p1.second)) and (p2.second<= max(p0.second,p1.second));

    return part1 and part2;
}