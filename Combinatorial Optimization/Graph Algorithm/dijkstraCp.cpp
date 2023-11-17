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
const int N = 1e5+200;

vpl g[N];
vll dist(N,INF);
vll vis(N,0);
vll parent(N,-1);
vll path;

void dijkstra(ll s, ll n)
{
    
    dist[s] = 0;
 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
 
    while (!q.empty())
    {
        ll currCost = q.top().first;
        ll currNode = q.top().second;
        q.pop();
 
        if (currCost > dist[currNode])
            continue;
        for (auto x : g[currNode])
        {
            ll cost = x.second;
            ll node = x.first;
            if (cost + currCost < dist[node])
            {
                dist[node] = cost + currCost;
                q.push({dist[node], node});
                parent[node] = currNode;
            }
        }
    }
}
void printPath(ll i)
{
    if (parent[i] == -1){
        path.push_back(i);
        return;
    }
    printPath(parent[i]);
    path.push_back(i);
    
}
int main()
{

    ll n,m;cin>>n>>m;
    
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w)); //u-> {v,w}
        g[v].push_back(make_pair(u,w)); //v-> {u,w}

    }

    dijkstra(1,n);

    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    if(dist[n]==INF) cout<<-1;
    else {
        printPath(n);
        for(auto it:path) cout<<it<<" ";
    }

    return 0;
}