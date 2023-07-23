#include <stdio.h>

void isAlphabet(char *str);

int main() {

    char w[100];
    printf("Enter your string:");
    scanf("%s",w);
    isAlphabet(w);
    return 0;
}

void isAlphabet(char *str){
    while(*str){
        if(*str!='1' && *str!='0') {
            printf("Not from alphabet\n");
            return;
        }
        str++;
    }
    printf("From Alphabet\n");
}
