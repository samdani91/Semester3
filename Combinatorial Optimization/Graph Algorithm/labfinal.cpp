#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

map<string,string>parent;
map<string,int>sz;

void make(string v);
string find(string v);
void Union(string a,string b);


int main()
{   
    freopen("labfinalinput.txt","r",stdin);

    int n,e;
    cin>>n>>e;

    vector<pair<int,pair<string,string>>>edges; //{w,{u,v}}

    int total_weight=0;

    while(e--){
        string u,v;
        int w;
        cin>>u>>v>>w;
        total_weight+=w;
        edges.push_back({w,{u,v}});
        parent.insert({u,""});
    }
    
    sort(edges.begin(),edges.end());

    for(auto it:parent){
        make(it.first);
    }

    int totalCost=0;
    for(auto &edge:edges){
        int w=edge.first;
        string u=edge.second.first;
        string v=edge.second.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        totalCost+=w;
    }
    cout<<"Maximum "<<total_weight-totalCost<<" rupee can be saved"<<endl;
}
void make(string v){
    parent[v]=v;
    sz[v]=1;
}

string find(string v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

void Union(string a,string b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}