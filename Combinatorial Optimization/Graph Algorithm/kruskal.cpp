#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int parent[N];

void make(int v){
    parent[v]=v;
}

int find(int v){
    if(v==parent[v]) return v;
    return find(parent[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<pair<int,pair<int,int>>>edges; //{w,{u,v}}

    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    
    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++) make(i);

    int totalCost=0;
    for(auto &edge:edges){
        int w=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        totalCost+=w;
        cout<<u<<" "<<v<<endl;
    }
    cout<<totalCost<<endl;
}
// a-1
// b-2
// c-3
// d-4
// e-5
// f-6
// g-7
// h-8
// i-9