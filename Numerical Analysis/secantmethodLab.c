#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(X) ((X*X*X)+4*X*X-10.0)
#define EPS 1.0e-6

double root(int n,double a,double b);

int main()
{
	
	double a,b;
	int i,n;
	a=1.25,b=2.0;
	n=100;
	
	printf("Root(SC):%lf\n",root(n,a,b));
	
	return 0;
}

double root(int n,double a,double b){
	int i;
	double c;
	printf("Iter	 a		b		c		f(a)		f(b)		f(c)\n");
	for(i=1;i<n;i++){
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
		printf("%3d	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf\n",i,a,b,c,f(a),f(b),f(c));
		
		if(fabs(f(c))<=EPS){
			return c;
		}
		a=b;
		b=c;

	}
	
	

}
