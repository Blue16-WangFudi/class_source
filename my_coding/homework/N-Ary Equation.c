#include <stdio.h>
#include <stdlib.h>

void forwardElimination(double **augmentedMatrix, int n);
void backSubstitution(double **augmentedMatrix, int n);

int main()
{
    int n; // Number of variables
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    double **augmentedMatrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        augmentedMatrix[i] = (double *)malloc((n + 1) * sizeof(double));
    }

    printf("Enter the augmented matrix (n x (n+1)):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%lf", &augmentedMatrix[i][j]);
        }
    }

    forwardElimination(augmentedMatrix, n);
    backSubstitution(augmentedMatrix, n);

    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %lf\n", i + 1, augmentedMatrix[i][n]);
    }

    for (int i = 0; i < n; i++)
    {
        free(augmentedMatrix[i]);
    }
    free(augmentedMatrix);

    return 0;
}

void forwardElimination(double **augmentedMatrix, int n)
{
    for (int col = 0; col < n; col++)
    {
        for (int row = col + 1; row < n; row++)
        {
            double ratio = augmentedMatrix[row][col] / augmentedMatrix[col][col];
            for (int i = col; i <= n; i++)
            {
                augmentedMatrix[row][i] -= ratio * augmentedMatrix[col][i];
            }
        }
    }
}

void backSubstitution(double **augmentedMatrix, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        augmentedMatrix[i][n] /= augmentedMatrix[i][i];
        augmentedMatrix[i][i] = 1.0;
        for (int row = i - 1; row >= 0; row--)
        {
            double factor = augmentedMatrix[row][i];
            augmentedMatrix[row][i] = 0.0;
            augmentedMatrix[row][n] -= factor * augmentedMatrix[i][n];
        }
    }
}
