#include<stdio.h>

void isPalindrome(char *str);
int len(char *str);

int main(int argc,char *argv[])
{
    char str[100];
    printf("Enter your string:");
    scanf("%s",str);

    isPalindrome(str);
    
    return 0;
}
int len(char *str){
    int count=0;
    while(*str){
        count++;
        str++;
    }
    return count;
}
void isPalindrome(char *str){
    int length=len(str);
    char *left=str;
    char *right=&str[length-1];

    while(left<=right){
        if(*left!=*right){
            printf("Not palindrome\n");
            return;
        }
        left++;
        right--;
    }
    printf("Palindrome\n");
}