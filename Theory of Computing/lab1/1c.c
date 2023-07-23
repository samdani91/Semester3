#include <stdio.h>

void concatenate(char *str1,char *str2);

int main() {
    char x[100],y[100];
    printf("Enter first string:");
    scanf("%s",x);
    printf("Enter second string:");
    scanf("%s",y);

    concatenate(x,y);

    printf("Concatenated string:%s\n",x);

    return 0;
}

void concatenate(char *str1,char *str2){
    while(*str1) str1++;
    while(*str2){
        *str1=*str2;
        str1++;
        str2++;
    }
    *str2='\0';
}