#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(X) ((X*X*X)+4*X*X-10.0)
#define EPS 1.0e-6

double root(int n,double a,double b,double c);

int main()
{
	
	double a,b,c;
	int i,n;
	a=1.25,b=1.5;
	n=100;
	
	if(!((f(a)*f(b))<0)) {
		printf("Roots are invalid\n");
		exit(0);
	}
	
	printf("Root(FP):%lf\n",root(n,a,b,c));
	
	return 0;
}

double root(int n,double a,double b,double c){
	int i;
	for(i=1;i<n;i++){
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
		printf("%3d %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",i,a,b,c,f(a),f(b),f(c));
		
		if(fabs(f(c))<=EPS){
			return c;
		}
		if(f(a)*f(c)<0) b=c;
		else a=c;

	}
	
	

}
