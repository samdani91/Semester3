#include<bits/stdc++.h>
using namespace std;

char transition[100][100][100];
int numOfState,numOfSymbol;
string output;
bool check=false;

void nfa(char startState,char finishState,string input,int curr,char *alpha,char *states,string path);

int main()
{

    freopen("input.txt","r",stdin);
    int numOfTransition,i,j,k;
    char startState,finishState;
    string input;
    cin>>numOfState>>numOfSymbol;

    char states[numOfState],alpha[numOfSymbol];

    for(i=0;i<numOfState;i++) cin>>states[i];
    for(i=0;i<numOfSymbol;i++) cin>>alpha[i];

    for(i=0;i<numOfState;i++){
        for(j=0;j<numOfSymbol;j++){
            cin>>numOfTransition;
            for(k=0;k<numOfTransition;k++){
                cin>>transition[i][j][k];
            }
            transition[i][j][k]='\0';
        }
    }
    
    cin>>startState>>finishState;
    cin>>input;

    nfa(startState,finishState,input,0,alpha,states,"");

    if(check==true){
        cout<<"Accepted"<<endl;
        for(i=0;i<output.size()-1;i++){
            cout<<output[i]<<"->";
        }
        cout<<output[i]<<endl;
    }else{
        cout<<"Rejected"<<endl;
    }

    return 0;
}
void nfa(char startState,char finishState,string input,int curr,char *alpha,char *states,string path){
    if(startState=='X') return;
    path+=startState;
    if(input[curr]=='\0' && startState!=finishState) return;
    if(input[curr]=='\0' && startState==finishState) {
        output=path;
        check=true;
        return;
    }
    int i,j,k;
    for(i=0;i<numOfState;i++){
        if(states[i]==startState) break;
    }
    for(j=0;j<numOfSymbol;j++){
        if(input[curr]==alpha[j]) break;
    }
    for(k=0;transition[i][j][k];k++){
        nfa(transition[i][j][k],finishState,input,curr+1,alpha,states,path);
    }

}