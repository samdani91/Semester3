#include<stdio.h>
#include<math.h>

/*
    20x + y – 2z = 17
    3x + 20y – z = -18
    2x – 3y + 20z = 25

*/

#define X(y,z) (17-y+(2*z))/20
#define Y(x,z) (-18-(3*x)+z)/20
#define Z(x,y) (25-(2*x)+(3*y))/20

#define EPS 1.0e-4

int main()
{

    double x,y,z,x1,y1,z1,e1,e2,e3;
    x=y=z=0;
    int i=1;

    printf("\ni\t   x\t   y\t   z\n");

    do{
        x1=X(y,z);
        y1=Y(x,z);
        z1=Z(x,y);

        printf("%d\t%0.4f\t%0.4f\t%0.4f\n",i, x1,y1,z1);

        e1=fabs(x1-x);
        e2=fabs(y1-y);
        e3=fabs(z1-z);

        i++;

        x=x1;
        y=y1;
        z=z1;

    }while(e1>EPS && e2>EPS && e3>EPS);

    printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);


    return 0;
}