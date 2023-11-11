#include<stdio.h>

int main()
{

    int n;
    double quotient;
    printf("Enter the number of x and f(x):");
    scanf("%d",&n);

    double x[n],fx[n];
    double lss[n][n-1];
    double transpose_lss[n-1][n];
    double const_matrix[n][1];
    double result[n-1][n-1];
    double const_prod_mat[n-1][1];
    double solution[n-1];

    printf("Enter the value of x and the value of f(x):\n");

    for(int i=0;i<n;i++){
        scanf("%lf %lf",&x[i],&fx[i]);
        const_matrix[i][0]=fx[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            lss[i][j]=1;
            for(int k=0;k<j;k++){
                lss[i][j]*=x[i];
            }
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            transpose_lss[i][j]=lss[j][i];
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            result[i][j]=0;
            for(int k=0;k<n;k++){
                result[i][j]+= transpose_lss[i][k]*lss[k][j];
            }
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<1;j++){
            const_prod_mat[i][j]=0;
            for(int k=0;k<n;k++){
                const_prod_mat[i][j]+= transpose_lss[i][k]*const_matrix[k][j];
            }
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            quotient=result[j][i]/result[i][i];
            const_prod_mat[j][0]-= quotient*const_prod_mat[i][0];
            for(int k=0;k<n-1;k++){
                result[j][k]-= quotient*result[i][k];
            }
        }
    }

    solution[n-2]=const_prod_mat[n-2][0]/result[n-2][n-2];

    for(int i=n-3;i>=0;i--){
        solution[i]=const_prod_mat[i][0];
        for(int j=i+1;j<n-1;j++){
            solution[i]-= solution[j]*result[i][j];
        }
        solution[i]/=result[i][i];
    }

    printf("f(x)= ");
    for(int i=0;i<n-1;i++){
        if(i==0) printf("%.2lf",solution[i]);
        else if(i==1) printf("+(%.2lf)*x",solution[i]);
        else printf("+(%.2lf)*x^%d\n",solution[i],i);
    }

    return 0;
}