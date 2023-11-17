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

const int N=1e4+10;
int dp[310][10010];

int nWays(int ind,int amount,vector<int>& coins)
{
    if(amount==0) return 1;
    if(ind<0) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int ways=0;
    for(int coin=0;coin<=amount;coin+=coins[ind]){
        if(amount-coin >= 0){
            ways+=nWays(ind-1,amount-coin,coins);
        }
        
    }
    return dp[ind][amount]=ways;
}
int change(int amount,vector<int>& coins) {
    memset(dp,-1,sizeof(dp));
    int ans=nWays(coins.size()-1,amount,coins);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    vector<int>coins={1,2,5};
    cout<<change(11,coins);

    

    return 0;
}