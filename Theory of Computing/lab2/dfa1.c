#include<stdio.h>

char dfa(char *str,char *path,char state);

int main()
{
    char str[50],state='A',path[100];
    printf("Enter string:");
    scanf("%s",str);

    state=dfa(str,path,state);
    if(state=='C') printf("Accepted\n");
    else printf("Not accepted\n");
    printf("%s\n",path);
    
    return 0;
}

char dfa(char *str,char *path,char state){
    int i=0,j=0;
    while(str[i]!='\0'){
        if(state=='A'){
            if(str[i]=='0'){
                state='B';
                path[j++]=state;
            }else{
                path[j++]=state;
            }
        }else if(state=='B'){
            if(str[i]=='0'){
                state='C';
                path[j++]=state;
            }else{
                state='A';
                path[j++]=state;     
            }
        }else if(state=='C'){
            if(str[i]=='0'){
                path[j++]=state;
            }else{
                state='A';
                path[j++]=state;
            }
        }
        i++;
    }
    return state;
}