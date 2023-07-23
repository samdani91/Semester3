#include<stdio.h>
#include<math.h>

double findRoot(int n,double x1,double x2);
double f(double x);

int main(int argc,char *argv[])
{
    int n,x1,x2;
    printf("Number of iteration:");
    scanf("%d",&n);
    printf("Enter x1 and x2:");
    scanf("%d %d",&x1,&x2);

    if(!((f(x1)*f(x2))<0)) printf("Roots are invalid\n");
    else printf("Root of the given equation:%lf\n",findRoot(n,x1,x2));

    return 0;
}

double f(double x){
    double value=pow(x,3)-(2*x)-5;
    return value;
}

double findRoot(int n,double x1,double x2){
    double root;
    int i=1;
    while(i<=n){
        root=(x1+x2)/2;
        if((f(root)*f(x1))<0) x2=root;
        else x1=root;

        i++;
    }

    return root;

}