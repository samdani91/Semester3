#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 3
#define EPS 0.1

int main (void) {
  int i, j, k;
  double x[NMAX][NMAX+1]= { {4,-1,1,8}, {2,5,2,3}, {1,2,4,11}};
  double mij,temp;

  for (i=0; i<NMAX; i++ ){
    for (j=0; j<NMAX+1; j++ )
      printf("%7.2lf "  ,x[i][j]);
    printf("\n");
  }
  printf("\n");

  for (i=0; i<NMAX-1; i++ ) { 
    if (fabs(x[i][i]) < EPS) {
      for (j=i+1; j<NMAX; j++ ){
        if (fabs(x[j][i]) > EPS) {
          for (k=i; k<NMAX+1; k++ )
          {
            temp = x[i][k];
            x[i][k] = x[j][k];
            x[j][k] = temp;
          } 
          break;   
        }
      }
    }
    for (j=i+1; j<NMAX; j++ ){
      mij = x[j][i]/x[i][i];
      for (k=i; k<NMAX+1; k++ )
      {
        x[j][k] = x[j][k] - mij * x[i][k];
      }
    }
  }

  for (i=0; i<NMAX; i++ ){
    for (j=0; j<NMAX+1; j++ )
      printf("%7.2lf "  ,x[i][j]);
    printf("\n");
  }
  printf("\n");

  return 0;
}
