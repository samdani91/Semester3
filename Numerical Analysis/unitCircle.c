#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265

int main(int argc,char *argv[])
{

    double a,b,h;
    double x[101],y[100],dy[101];
    int n=100;
    a=0,b=2*PI;
    h=(b-a)/n;

    x[0]=a;
    y[0]=sin(x[0]);

    printf("\"f(x)\",\"f'(x)\"\n");

    for(int i=1;i<n;i++){
        x[i]=x[i-1]+h;
        y[i]=sin(x[i]);
    }
    x[n]=b;
    y[n]=sin(x[n]);

    dy[0]=(y[1]-y[0])/(x[1]-x[0]);

    for(int i=1;i<n;i++){
        dy[i]=(y[i+1]-y[i-1])/(x[i+1]-x[i-1]);
    }
    dy[n]=(y[n]-y[n-1])/(x[n]-x[n-1]);

    for(int i=0;i<=n;i++){
        printf("%lf,%lf\n",y[i],dy[i]);
    }

    return 0;
}