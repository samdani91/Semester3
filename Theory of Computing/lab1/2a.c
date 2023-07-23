#include<stdio.h>

void generateStrings(int k);
int power(int k);

int main(int argc,char *argv[])
{

    int k;
    printf("Enter k:");
    scanf("%d",&k);

    if(k==0) printf("NULL\n");
    else generateStrings(k);

    return 0;
}

int power(int k){
    int res=2;
    for(int i=1;i<k;i++) res*=2;
    return res;
}

void generateStrings(int k){
    for(int i=0;i<power(k);i++){
        int temp=i;
        for(int j=0;j<k;j++){
            printf("%d",temp%2);
            temp/=2;
        }
        printf("\n");
    }
}
