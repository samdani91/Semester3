#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
vector<vector<int>>graph;

void bellmanFord(int n,int src)
{
    vector<int>dist(n+1,INF);
    dist[src]=0;
    bool change;
    for(int i=0;i<n-1;i++){
        change=false;
        for(auto it:graph){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            if(dist[v] > w+dist[u]) change=true;

            dist[v]=min(dist[u]+w,dist[v]);
        }
    }

    if(change){
        cout<<"Negative weighted cycle exist\n";
        return ;
    }

    cout<<"Shortest Paths:\n";
    for(auto it:dist){
        if(it!=INF) cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    freopen("bfinput.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back({u,v,w});
    }
    int src;cin>>src;

    bellmanFord(n,src);

    return 0;
}