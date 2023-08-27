#include <stdio.h>
#include <math.h>

#define EPS 0.1e5
#define row1 4
#define col1 4

double augmentedMatrix[row1][col1 + 1];

//(int *)arr

int main()
{
    freopen("gaussinput.txt", "r", stdin);
    int i, j, k;
    double temp;

    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1 + 1; j++)
        {
            scanf("%lf", &augmentedMatrix[i][j]);
        }
    }

    printf("\nAugmented Matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1 + 1; j++)
        {
            printf("%.2lf\t", augmentedMatrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < row1-1; i++)
    {
        if (fabs(augmentedMatrix[i][i]) < EPS)
        {
            for (j = i+1; j < row1; j++)
            {
                if (fabs(augmentedMatrix[j][i]) > EPS)
                {
                    for (k = i; k < row1 + 1; k++)
                    {
                        temp = augmentedMatrix[i][k];
                        augmentedMatrix[i][k] = augmentedMatrix[j][k];
                        augmentedMatrix[j][k] = temp;
                    }
                    break;
                }
            }
        }
    }
    for (j = i+1; j < row1; j++)
    {
        if (j > i)
        {
            double ratio = augmentedMatrix[j][i] / augmentedMatrix[i][i];
            for (k = 0; k < col1 + 1; k++)
            {
                augmentedMatrix[j][k] -= (augmentedMatrix[i][k] * ratio);
            }
        }
    }
    printf("\nUpper Triangular Matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1 + 1; j++)
        {
            printf("%.2lf\t", augmentedMatrix[i][j]);
        }
        printf("\n");
    }
}
