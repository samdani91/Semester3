#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("input.txt");

    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string line,temp;
    int lineNum=0;

    while(!file.eof())
    {
        getline(file,line);
        lineNum++;
        if(line.find("//")!=string::npos){
            int i=0;
            while(line[i]!='/') i++;
            i+=2;
            while(line[i]) {
                temp+=line[i];
                i++;
            }
            cout<<lineNum<<": "<<temp<<endl;
            temp.clear();
        }
        else if(line.find("/*")!=string::npos && line.find("*/")!=string::npos){
            int i=0;
            while(line[i]!='/') i++;
            i+=2;

            while(line[i]!='*'){
                temp+=line[i];
                i++;
            }
            cout<<lineNum<<": "<<temp<<endl;
            temp.clear();
        }
        else if(line.find("/*")!=string::npos&& line.find("*/")==string::npos){
            int i=0;
            while(line[i]!='/') i++;
            i+=2;
            while(line[i]){
                temp+=line[i];
                i++;
            }
            cout<<lineNum<<": "<<temp<<endl;
            temp.clear();
            //line.clear();
            while(getline(file,line))
            {
                lineNum++;
                if(line.find("*/")!=string::npos)break;
                i=0;
                while(line[i]==' ') i++;
                while(line[i]){
                    temp+=line[i];
                    i++;
                }
                cout<<lineNum<<": "<<temp<<endl;
                temp.clear();
                line.clear();

            }
            
        }
    }
    file.close();
}