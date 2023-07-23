#include<stdio.h>
#include<math.h>

#define PI 3.1416

int main(int argc,char *argv[])
{

    int n=100;
    double a=0,b=2*PI,h,x;
    h=(b-a)/n;
    printf("\"x\",\"cos(x)\"\n");
    x=a;
    printf("%lf,%lf\n", x,cos(x));

    for(int i=1;i<n;i++){
        x+=h;
        printf("%lf,%lf\n", x,cos(x));
    }

    x=b;
    printf("%lf,%lf\n", x,cos(x));

    return 0;
}