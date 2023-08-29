#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define f(X) ((X*X)+1.0)

int main(int argc,char *argv[])
{

    double a,b,h;
    double x[11],y[11],dy[11];
    int n=10;
    a=0,b=2;
    h=(b-a)/n;

    x[0]=a;
    y[0]=f(x[0]);

    printf("\"x\",\"f(x)\",\"f'(x)\"\n");

    for(int i=1;i<n;i++){
        x[i]=x[i-1]+h;
        y[i]=f(x[i]);
    }
    x[n]=b;
    y[n]=f(x[n]);


    for(int i=0;i<n;i++){
        dy[i]=(y[i+1]-y[i])/h;
    }

    for(int i=0;i<=n;i++){
        printf("%3d %lf,%lf,%lf\n",i,x[i],y[i],dy[i]);
    }

    return 0;
}