#include<bits/stdc++.h>
using namespace std;

#define V 6

bool BFS(int rGraph[V][V],int source,int sink,int *parent)
{   

    bool vis[V];
    memset(vis,0,sizeof(vis));

    queue<int>q;
    q.push(source);
    vis[source]=true;

    parent[source]=-1;

    while(!q.empty()){
        int curr_v=q.front();
        q.pop();
        for(int v = 0; v < V; v++){
            if(!vis[v] and rGraph[curr_v][v]>0){

                if(v==sink){
                    parent[v]=curr_v;
                    return true;
                }
                q.push(v);
                parent[v]=curr_v;
                vis[v]=true;
            }
        }
    }

    return false;
}

int fordFulkerson(int graph[V][V],int source,int sink)
{
    int rGraph[V][V];
    int parent[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            rGraph[i][j]=graph[i][j];
        }
    }

    int ans=0;
    int u,v;

    vector<int>augPath;
    cout<<"Augmented Path:\n\n";

    while(BFS(rGraph,source,sink,parent)){
        int path_flow=INT32_MAX;
        for(v=sink;v!=source;v=parent[v]){
            augPath.push_back(v);
            u=parent[v];
            path_flow=min(path_flow,rGraph[u][v]);
        }
        augPath.push_back(source);

        for(v=sink;v!=source;v=parent[v]){
            u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }
        
        ans+=path_flow;

        for(int i=augPath.size()-1;i>=0;i--) cout<<augPath[i]<<" ";
        cout<<endl;
        augPath.clear();
    }

    return ans;
}
int main()
{
    freopen("ffinput.txt","r",stdin);

    int graph[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
 
    int mxFlow=fordFulkerson(graph,0,5);

    cout<<"\nMaximum Flow:"<<mxFlow<<endl;
}