#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPS 10.0e-6


double h(double x)
{
  return (sqrt(x) - (x*x));
}
double BiSec(double a,double b,int n)
{

   int i;
   double c , x;

   if(h(a)*h(b) > 0)
    {
     printf("[%lf,%lf] : No Root.....\n",a,b);
     exit(0);  
    }

    for(i=1;i<n;i++)
    {
     // get Root
     c = (a+b)/2;
         
        if(h(a)*h(c) < 0)b = c;

        else a = c;

    

      if(fabs(h(c)) <= EPS)
      {
        //printf("Root(BS) = %lf\n",c);
        return c;
      }

    }

}

void numerical_integration(double a,double b,int N)
{
  int i;

  double H = (b - a) / N;
  
  double sum_X , sum_I = 0.0 , Integral , x[11] , y[11];

  x[0] = a;

  for( i=1;i<N;i++)
  {
    x[i] = x[i-1] + H;
  }

  x[N] = b;

  
   
  for( i=0;i<=N;i++)
  {
    y[i] = fabs(h(x[i]));
  }

  sum_X = h(0) + h(N);

  for( i=1;i<N;i++)
   {
     sum_I += y[i];
   }

   Integral = (H * (sum_X + (2*sum_I))/2);

   printf("%lf",Integral);

 /*  for(int i=0;i<11;i++)
   {
     printf("%lf %lf\n",x[i],y[i]);
   }*/
}

void simpson_integration(double a,double b,int N)
{

  if( N % 2 != 0)N++;

  double H = (b - a) / N;
  
  double sum_X , sum_I = 0.0 , sum_O ,sum_E ,Integral , x[11] , y[11];

  x[0] = a;

  for(int i=1;i<=N-1;i++)
  {
    x[i] = x[i-1] + H;
  }

  x[N] = b;

 
   
  for(int i=0;i<=N;i++)
  {
    y[i] = h(x[i]);
  }

   sum_X = y[0] + y[N];

  for(int i=1;i<=N-1;i++)
   {
     if(i %2 != 0)
       sum_O += y[i];
   }

  for(int i=2;i<=N-2;i++)
   {
      if(i %2 == 0)
       sum_E += y[i];
   }

   Integral = fabs(H*(sum_X + (4*sum_O) + (2*sum_E))/3);

   printf("%lf",Integral);
}


int main()
{
   printf("%lf\n",BiSec(0.5,1.25,100));

   double intersect = BiSec(0.5,1.25,100);

   
   
   simpson_integration(0.0,intersect,10);
   printf("\n");
   numerical_integration(0.0,intersect,10);
  

}
