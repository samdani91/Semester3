#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void generateStrings(int n);

int main() {
    srand(time(NULL));
    int num_strings = 5;
    generateStrings(num_strings);

    return 0;
}

void generateStrings(int n) {
    char alphabet[] = "01";

    int i, j;
    for (i = 0; i < n; i++) {
        int length = rand()%5 +1;
        //char str[length];
        for (j = 0; j < length; j++) {
            int index = rand() % 2;
            //str[j]=alphabet[index];
            printf("%c",alphabet[index]);
        }
        //str[j]='\0';
        //printf("%s\n",str);
        printf("\nLength:%d\n",length);
    }
}