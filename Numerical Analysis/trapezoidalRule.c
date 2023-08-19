#include<stdio.h>

#define f(X) ((X*X)+1.0)

int main()
{

    int n=10;
    double a,b,h,x[n+1],y[n+1],sum_x,sum_I=0,output;
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
    for(int i=1;i<n;i++){
        sum_I+=y[i];
    }
    output=(h*(sum_x+(2*sum_I)))/2;

    printf("Trapezoidal Rule ----------\n");
    printf("Integral value:%lf\n",output);
    printf("---------------------------\n");

    return 0;
}