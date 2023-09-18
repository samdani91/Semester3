#include<bits/stdc++.h>
using namespace std;

typedef  long long int          ll;
typedef  long double            ld;
typedef  string                 str;
typedef  vector<ll>             vll;
typedef  vector<string>         vs;
typedef  vector<pair<ll, ll>>   vpl;
typedef  set<ll>                sll;
typedef  map<ll,ll>             mll;
typedef  pair<int,int>          pint;
typedef  pair<ll,ll>            pll;
double   pi = acos(-1.0);
#define  debug(x)              cerr<<#x<< <<x<<endl;
#define  loop                   for(ll i=1; i<=n; i++)
#define  all(a)                 (a).begin(), (a).end()
#define  min3(a,b,c)            min(a,min(b,c))
#define  max3(a,b,c)            max(a,max(b,c))
#define  min4(a,b,c,d)          min(a,min(b,min(c,d)));
#define  max4(a,b,c,d)          max(a,max(b,max(c,d)));

const int INF = 1e9+10;
const int N = 1e5+10;

vector<pair<int,int>>g[N];
vector<int>dist(N,INF);
vector<int>vis(N,0);

void dijkstra(int source)
{
    set<pair<int,int>>st; //weight,node
    st.insert(make_pair(0,source));
    dist[source]=0;

    while(st.size()>0){
        auto node= *st.begin();
        int v=node.second;
        int v_dis=node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;
        for(auto child : g[v]){
            int child_v=child.first;
            int wt=child.second;
            if(dist[v]+wt < dist[child_v]){
                dist[child_v]=dist[v]+wt;
                st.insert(make_pair(dist[child_v],child_v));
            }
        }
    }
}
int main()
{

    int n,m;
    
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w)); //u-> {v,w}

    }

    return 0;
}