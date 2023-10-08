#include<bits/stdc++.h>
using namespace std;

int horner(int p[],int n,int x);
void rabinkarp(string T,string P,int d,int q);

int main()
{

    // int p[]={2,-6,2,1};
    // int n=sizeof(p)/sizeof(p[0]);
    // int x=5;

    // cout<<horner(p,n,x)<<endl;

    string T,P;
    cin>>T>>P;

    int d=26;
    int q=13;

    rabinkarp(T,P,d,q);

    return 0;
}

void rabinkarp(string T,string P,int d,int q)
{
    int n=T.size();
    int m=P.size();
    int h=1;
    int p,t;
    p=t=0;

    for(int i=0;i<m-1;i++) h= (h*d) % q;

    //horner rule
    for(int i=0;i<m;i++){
        p=(p*d + P[i])%q;
        t=(t*d + T[i])%q;
    }

    for(int s=0;s<=n-m;s++){
        if(p==t){
            for(int i=0;i<m;i++){
                if(T[s+i]!=P[i]) break;
                if(i==m-1){
                    cout<<"Pattern found at index "<<s<<endl;
                }
            }
        }
        if(s<n-m){
            t=(d*(t-T[s]*h) + T[s+m])%q; //rolling hash
            if(t<0) t+=q;
        }
    }

}

int horner(int p[],int n,int x)
{
    int res=p[0];
    for(int i=1;i<n;i++) res = res*x + p[i];

    return res;
}