#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(X) ((X*X*X)+4*X*X-10.0)
#define g(x) sqrt((10-(x*x*x))/4)
#define EPS 1.0e-6

double root(int n,double a);

int main()
{
	
	double a;
	int i,n;
	a=1.25;
	n=100;
	
	
	printf("Root(FP):%lf\n",root(n,a));
	
	return 0;
}

double root(int n,double a){
	int i;
	double x1=a,x2;
	for(i=1;i<n;i++){
		x2=g(x1);
		printf("%3d %.6lf %.6lf %.6lf %.6lf\n",i,x1,x2,g(x1),f(x2));
		
		if(fabs(f(x2))<=EPS){
			return x2;
		}
		x1=x2;
	}
	
	

}
