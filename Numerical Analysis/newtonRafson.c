#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(X) ((X*X)-3*X+2.0)
#define fp(X) (2*X-3)
#define EPS 1.0e-6

double root(int n,double a);

int main()
{
	
	double a;
	int i,n;
	a=0;
	n=100;
	
	
	printf("Root(NR):%lf\n",root(n,a));
	
	return 0;
}

double root(int n,double a){
	int i;
	double x1=a,x2;
	for(i=1;i<n;i++){
		x2=x1-(f(x1)/fp(x1));
		printf("%3d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n",i,x1,x2,f(x1),fp(x1),f(x2));
		
		if(fabs(f(x2))<=EPS){
			return x2;
		}
		x1=x2;
	}
	
	

}
