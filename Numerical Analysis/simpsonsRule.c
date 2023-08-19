#include<stdio.h>

#define f(X) ((X*X)+1.0)

int main()
{

    int n=10;
    if(n%2!=0) n=n+1;
    double a,b,h,x[n+1],y[n+1],sum_x,sum_O=0,sum_E=0,output;
    a=0.0,b=2.0;
    h=(b-a)/n;

    x[0]=a;
    x[n]=b;
    for(int i=1;i<n;i++){
        x[i]=x[i-1]+h;
    }
    for(int i=0;i<=n;i++){
        y[i]=f(x[i]);
    }
    sum_x=y[0]+y[n];
    for(int i=1;i<=n-1;i+=2){
        sum_O+=y[i];
    }
    for(int i=2;i<=n-2;i+=2){
        sum_E+=y[i];
    }
    output=(h*(sum_x+(4*sum_O)+(2*sum_E)))/3;

    printf("Simpson's 1/3 Rule --------\n");
    printf("Integral value:%lf\n",output);
    printf("---------------------------\n");

    return 0;
}