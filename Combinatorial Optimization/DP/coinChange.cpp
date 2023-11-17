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
int dp[N];

int minCoin(int amount,vector<int>& coins)
{
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    int ans=INT32_MAX;
    for(int coin:coins){
        if(amount-coin >= 0)
        ans=min(ans+0LL,minCoin(amount-coin,coins)+1LL);
    }
    return dp[amount]=ans;
}
int coinChange(vector<int>& coins, int amount) {
    memset(dp,-1,sizeof(dp));
    int ans=minCoin(amount,coins);
    return ans==INT32_MAX ? -1 : ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    vector<int>coins={1,2,5};
    cout<<coinChange(coins,11);

    

    return 0;
}