#include <stdio.h>
#include <math.h>
#define MAX 3
#define EPS 0.1

void gaussian();
void LU();
void printMatrix(double M[][MAX]);

double mat[MAX][MAX] = {{4, -3, 1}, {-2, 1, -3}, {1, -1, 2}};
double L[MAX][MAX] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
double U[MAX][MAX] = {{4, -3, 1}, {-2, 1, -3}, {1, -1, 2}};
double product[MAX][MAX];

int main()
{

    gaussian();

    printf("A matrix:\n");
    printMatrix(mat);

    printf("U matrix:\n");
    printMatrix(U);

    printf("L matrix:\n");
    printMatrix(L);

    LU();

    printf("LU matrix:\n");
    printMatrix(product);
}

void gaussian()
{
    int i, j, k;
    double mij;

    for (i = 0; i < MAX - 1; i++)
    {
        if (fabs(U[i][i]) < EPS)
        {
            for (j = i + 1; j < MAX; j++)
            {
                if (fabs(U[j][i]) > EPS)
                {
                    for (k = i; k < MAX + 1; k++)
                    {
                        double temp = U[i][k];
                        U[i][k] = U[j][k];
                        U[j][k] = temp;
                    }
                    break;
                }
            }
        }
        for (j = i + 1; j < MAX; j++)
        {
            mij = U[j][i] / U[i][i];
            L[j][i]=mij;
            for (k = i; k < MAX + 1; k++)
            {                     
                U[j][k] = U[j][k] - mij * U[i][k];
            }
        }
    }
}
void LU()
{
    for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			for(int k=0;k<MAX;k++){ 
				product[i][j]+=L[i][k]*U[k][j];
			
			}
		}
	}
}
void printMatrix(double M[][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%7.2lf", M[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}