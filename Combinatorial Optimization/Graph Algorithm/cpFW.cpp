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

const int N=510;
const int INF=1e9+10;

ll dist[N][N];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }

    ll n,e;cin>>n>>e;
    while(e--){
        ll u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(dist[i][k]!=INF and dist[k][j]!=INF){
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
    }

    for(int j=1;j<=n;j++){
        cout<<dist[1][j]<<" ";
    }
    cout<<endl;

    return 0;
}