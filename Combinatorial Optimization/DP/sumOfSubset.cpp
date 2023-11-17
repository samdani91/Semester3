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

int dp[205][20005];
vector<int>chosenSubset,currSubset;

bool func(int i,int sum,vector<int>&nums)
{   
    if(sum==0) {
        chosenSubset=currSubset;
        return true;
    }
    if(i<0) return false;
    if(dp[i][sum]!=-1) return dp[i][sum];

    bool exclude=func(i-1,sum,nums);//not consider ith index
    currSubset.push_back(nums[i]);
    bool include=false;

    if(sum-nums[i]>=0){
        include=func(i-1,sum-nums[i],nums); //consider ith index
    }
    currSubset.pop_back();

    return dp[i][sum]=(exclude || include);
}

bool canPartition(int sum,vector<int>& nums)
{   
    memset(dp,-1,sizeof(dp));
    // int sum=accumulate(nums.begin(),nums.end(),0);
    // if(sum%2!=0) return false;
    // sum/=2;
    return func(nums.size()-1,sum,nums);
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n,k;cin>>n>>k;
    vector<int>nums;
    loop{
        int x;cin>>x;
        nums.push_back(x);
    }
    
    if(canPartition(k,nums)){
        cout<<"YES\n";
        for(int i=chosenSubset.size()-1;i>=0;i--) cout<<chosenSubset[i]<<" ";
    }else{
        cout<<"NO\n";
    }


    return 0;
}