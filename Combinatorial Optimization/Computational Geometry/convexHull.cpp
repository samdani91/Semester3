#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> point;

point p0;

void convexHull(vector<point>&points,int numPoints);
int bottomMostPoint(vector<point>&points,int numPoints);
int direction(point p,point q,point r);
int compare(const void *vp1,const void *vp2);
int distSq(point p1, point p2);
point nextToTop(stack<point> &s);

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    freopen("convexHullinput.txt","r",stdin);
    
    vector<point> points;
    
    int numPoints; cin>>numPoints;

    for(int i=1;i<=numPoints;i++){
        int x,y; cin>>x>>y;
        points.push_back({x,y});
    }

    convexHull(points,numPoints);


    return 0;
}

void convexHull(vector<point>&points,int numPoints)
{
    //Find the bottommost point
    int min=bottomMostPoint(points,numPoints);

    swap(points[0],points[min]);

    p0=points[0];
    qsort(&points[1],numPoints-1,sizeof(point),compare);

    int n=1;
    for(int i=1;i<numPoints;i++){
        while(i< numPoints-1 and direction(p0,points[i],points[i+1])==0){
            i++;
        }

        points[n]=points[i];
        n++;
    }

    if(n<3) return; //convex hull not possible

    stack<point>s;
    
    for(int i=0;i<3;i++){
        s.push(points[i]);
    }

    for(int i=3;i<n;i++){
        while(s.size()>1 and direction(nextToTop(s),s.top(),points[i]) >-1){
            s.pop();
        }
        s.push(points[i]);
    }

    while(!s.empty()){
        point temp=s.top();
        cout<<"("<<temp.first<<","<<temp.second<<")"<<endl;
        s.pop();
    }

}


int bottomMostPoint(vector<point>&points,int numPoints)
{
    int min_y=points[0].second;
    int min=0;

    for(int i=1;i<numPoints;i++){
        int curr_y=points[i].second;

        if((curr_y < min_y) or (min_y==curr_y and points[i].first<points[min].first)){
            min_y=points[i].second;
            min=i;
        }
    }

    return min;
}

int direction(point p,point q,point r)
{   
    int crossProduct=((q.first-p.first)*(r.second-p.second))-((r.first-p.first)*(q.second-p.second));
    return crossProduct; //-1 -> cc, 0-> co-linear ,1 ->c
}

int distSq(point p1, point p2)
{
    return (p1.first - p2.first)*(p1.first - p2.first) +(p1.second - p2.second)*(p1.second - p2.second);
}

int compare(const void *vp1,const void *vp2)
{
    point *p1= (point *)vp1;
    point *p2= (point *)vp2;

    int d=direction(p0,*p1,*p2);

    if(d==0){
        return (distSq(p0,*p2) >= distSq(p0,*p1)) ?  -1 : 1;
    }

    return d;

}

point nextToTop(stack<point> &s)
{
    point temp=s.top();
    s.pop();
    point ans=s.top();
    s.push(temp);
    return ans;
}