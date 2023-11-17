#include<bits/stdc++.h>
using namespace std;

const int INF=1e9+10;

#define min3(a,b,c) min(a,min(b,c));

int mat[100][100],a[100][100];
int r, c;

void PrintBest(int i,int j)
{
    if(i==0 or j==0 or j==c+1){
        return;
    }
    if(a[i-1][j-1]<=a[i-1][j] and a[i-1][j-1]<=a[i-1][j+1]){
        PrintBest(i-1,j-1);
    }
    else if(a[i-1][j]<=a[i-1][j-1] and a[i-1][j]<=a[i-1][j+1]){
        PrintBest(i-1,j);
    }
    else if(a[i-1][j+1]<=a[i-1][j-1] and a[i-1][j+1]<=a[i-1][j]){
        PrintBest(i-1,j+1);
    }
    // cout<<i<<" "<<j<<endl;
    cout<<mat[i][j]<<endl;
}
int main()
{
    
    cout<<"Please Enter Matrix size: ";
    cin>>r>>c;
    cout<<"Now Enter Matrix:\n";
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>mat[i][j];
        }
    }

    for(int i=1;i<=c;i++) {
        a[0][i]=0;
        a[1][i]=mat[1][i];
    }
    for(int i=0;i<=r;i++){
        a[i][0]=INF;
        a[i][c+1]=INF;
    }
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            a[i][j]= mat[i][j] + min3(a[i-1][j-1],a[i-1][j],a[i-1][j+1]);
        }
    }
    int cost=INF;
    int j;
    for(int i=1;i<=c;i++){
        if(a[r][i]<cost){
            cost=a[r][i];
            j=i;
        }
    }
    cout<<"Path Rating:"<<cost<<endl;
    // for(int i=1;i<=r;i++){
    //     for(int j=1;j<=c;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"Path:\n";
    PrintBest(r,j);

 return 0;
}