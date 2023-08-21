#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("knapsackinput.txt","r",stdin);
    int item,kanpsack;
    cin>>item>>kanpsack;

    int price[item],weight[item];
    int dp[item+1][kanpsack+1];

    for(int i=0;i<item;i++) cin>>weight[i];
    for(int i=0;i<item;i++) cin>>price[i];

    for(int j=0;j<=kanpsack;j++) dp[0][j]=0;
    for(int i=0;i<=item;i++) dp[i][0]=0;

    for(int i=1;i<item;i++){
        for(int j=1;j<kanpsack;j++){
            
        }
    }
}