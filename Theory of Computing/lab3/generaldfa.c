#include<stdio.h>
#include<stdlib.h>

int main()
{
    // FILE *fp;
    // fp=fopen("input.txt","r");
    
    int alpha,state,transition;
    char str[50],start,end;
    printf("Enter no of alphabet,state and transition:");
    scanf("%d %d %d",&alpha,&state,&transition);

    char matrix[state][alpha],set_state[state],set_alphabet[alpha];

    for(int i=0;i<state;i++){
        printf("Enter state:");
        scanf(" %c",&set_state[i]);
        getchar();
    }
    for(int i=0;i<alpha;i++){
        printf("Enter alphabet:");
        scanf(" %c",&set_alphabet[i]);
        getchar();
    }

    for(int i=0;i<state;i++){
        printf("State %c:\n",set_state[i]);
        for(int j=0;j<alpha;j++){
            printf("If %c then:",set_alphabet[j]);
            scanf(" %c",&matrix[i][j]);
        }

    }
    printf("Enter string:");
    scanf("%s",str);
    printf("Enter starting state:");
    scanf(" %c",&start);
    printf("Enter finishing state:");
    scanf(" %c",&end);

    int i=0;
    char curr=start;
    while(str[i]!='\0'){
        int r=start-set_state[0];
        printf("%c - ",start);
        int c=str[i]-'0';
        start=matrix[r][c];
        i++;
    }
    printf("%c - ",start);
    if(start==end){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;
}
