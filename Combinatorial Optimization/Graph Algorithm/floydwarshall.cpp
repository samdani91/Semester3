#include <bits/stdc++.h>
using namespace std;

const int MAX=100;
const int INF=INT32_MAX;

map<string, int> names;
int edges;
int graph[MAX][MAX] = {0};
int D[MAX][MAX]={0};
int P[MAX][MAX]={0};


void readInput();
void printGraph(int G[][MAX]);
void initialize_prededecessor_matrix();
void floyd_warshall();
void printPath(int s,int d);



int main()
{
    freopen("floydinput.txt", "r", stdin);

    string source,dest;

    readInput();

    floyd_warshall();

    cout<<"Floyd Warshall APSP: "<<endl<<endl;
    //cout<<"Source:";
    cin>>source;
    //cout<<"Destination:";
    cin>>dest;

    printPath(names[source],names[dest]);

    for(auto vertices:names){
        if(vertices.second==names[dest]){
            cout<<vertices.first<<endl;
        }
    }

    return 0;
}

void readInput()
{   
    
    string s;
    cin>>edges;
    int w, x, y, i = 0;
    
    while (edges--){
        
        cin>>s;
        
        if (names[s] == 0)
        {
            names[s] = ++i;
        }
        x = names[s];
        cin >> s;
        if (names[s] == 0)
        {
            names[s] = ++i;
        }
        y = names[s];
        cin >> w;
        graph[x][y] = w;
    }

    for (int i = 1; i <= names.size(); i++){
        for (int j = 1; j <= names.size(); j++){   
            if(i!=j && graph[i][j]==0) graph[i][j]=INF;
        }
    }
}
void floyd_warshall()
{
    for (int i = 1; i <= names.size(); i++){
        for (int j = 1; j <= names.size(); j++){   
            D[i][j]=graph[i][j];
        }
    }

    initialize_prededecessor_matrix();

    for(int k=1;k<=names.size();k++){
        for(int i=1;i<=names.size();i++){
            for(int j=1;j<=names.size();j++){
                if(D[i][k]!=INF && D[k][j]!=INF){
                    if(D[i][k] + D[k][j] < D[i][j]){
                        D[i][j]=D[i][k] + D[k][j];
                        P[i][j]=P[k][j];
                    }
                }
            }
        }
    }
    
}
void initialize_prededecessor_matrix()
{
    for(int i=1;i<=names.size();i++){
        for(int j=1;j<=names.size();j++){
            if(i==j || graph[i][j]==INF) P[i][j]=INF;
            else if(i!=j && graph[i][j]<INF) P[i][j]=i;
        }
    }
}
void printGraph(int G[][MAX])
{
    for (int i = 1; i <= names.size(); i++){
        for (int j = 1; j <= names.size(); j++){   
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl<<endl<<endl;;
}

void printPath(int s,int d)
{
    if (P[s][d]== INF){
        cout<<"No Path"<<endl;
        return;
    }
    else if(P[s][d]==s){
        for (auto vertices : names){
            if (vertices.second == s){
                cout << vertices.first << " -> ";
                break;
            }
        }
    }
    else{
        printPath(s,P[s][d]);
        printPath(P[s][d],d);
    }
    
}