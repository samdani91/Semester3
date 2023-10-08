#include<bits/stdc++.h>
using namespace std;

void KMP(string s,string p);
vector<int> prefixArray(string p);

int main()
{   
    
    freopen("kmpinput.txt","r",stdin);
    string s,p;
    cin>>s>>p;

    KMP(s,p);

    return 0;
}

vector<int> prefixArray(string p)
{
    int n=p.size();
    vector<int>prefix(n,0);

    int i,j=0;
    for(i=1;i<n;){
        if(p[i]==p[j]){
            prefix[i]=j+1;
            j++;
            i++;
        }else{
            if(j!=0){
                j=prefix[j-1];
            }else{
                prefix[i]=0;
                i++;
            }
        }
    }
    return prefix;
}

void KMP(string s,string p)
{
    vector<int>prefix=prefixArray(p);
    int i,j;
    i=j=0;

    int n=s.size();
    int m=p.size();

    while(i<n and j<m){
        if(s[i]==p[j]){
            i++;j++;
        }
        if(j==m){
            cout<<"Pattern Found At Index "<<i-j<<endl;
            j=prefix[j-1];
        }
        else if(i<n and s[i]!=p[j]){
            if(j!=0){
                j=prefix[j-1];
            }else{
                i++;
            }
        }
    }

}