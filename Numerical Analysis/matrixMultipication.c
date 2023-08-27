#include<stdio.h>

#define row1 3
#define col1 3
#define row2 3
#define col2 3

double mat1[row1][col1];
double mat2[row2][col2];
double res[row1][col2];


int main()
{
	freopen("input.txt","r",stdin);

	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			scanf("%lf",&mat1[i][j]);
		}
	}
	
	printf("\nMatrix 1:\n");
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			printf("%.2lf\t",mat1[i][j]);
		}
		printf("\n");
	}

	for(int i=0;i<row2;i++){
		for(int j=0;j<col2;j++){
			scanf("%lf",&mat2[i][j]);
		}
	}
	
	printf("\nMatrix 2:\n");
	for(int i=0;i<row2;i++){
		for(int j=0;j<col2;j++){
			printf("%.2lf\t",mat2[i][j]);
		}
		printf("\n");
	}

	for(int i=0;i<row1;i++){
		for(int j=0;j<col2;j++){
			for(int k=0;k<col1;k++){
				res[i][j]+=mat1[i][k]*mat2[k][j];
			
			}
		}
	}
	
	printf("\nProduct Result:\n");
	for(int i=0;i<row1;i++){
		for(int j=0;j<col2;j++){
			printf("%.2lf\t",res[i][j]);
		}
		printf("\n");
	}
	

}

