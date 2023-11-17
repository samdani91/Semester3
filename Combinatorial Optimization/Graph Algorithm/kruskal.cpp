#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int parent[N];
int sz[N];

void make(int v);
int find(int v);
void Union(int a,int b);


int main()
{   
    freopen("kruskalinput.txt","r",stdin);

    int n,e;
    cin>>n>>e;

    vector<pair<int,pair<int,int>>>edges; //{w,{u,v}}
    map<char,int>mp;

    while(e--){
        char u,v;
        int w;
        cin>>u>>v>>w;
        if(mp[u]==0)mp[u]=u-96;
        if(mp[v]==0) mp[v]=v-96;
        edges.push_back({w,{mp[u],mp[v]}});
    }
    
    sort(edges.begin(),edges.end());

    for(auto it:mp){
        make(it.second);
    }

    int totalCost=0;
    for(auto &edge:edges){
        int w=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        totalCost+=w;
        cout<<char(u+96)<<" "<<char(v+96)<<endl;
    }
    cout<<totalCost<<endl;
}
void make(int v){
    parent[v]=v;
    sz[v]=1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}