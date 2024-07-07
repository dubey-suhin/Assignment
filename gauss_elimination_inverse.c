#include <stdio.h>

int main()
{
    int n, i, j, k;
    float A[20][20], ratio, identity[20][20];

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    // Input the matrix A
    printf("Enter the elements of the matrix A:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // Initialize identity matrix
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                identity[i][j] = 1;
            else
                identity[i][j] = 0;
        }
    }

    // Applying Gauss-Jordan elimination
    for (i = 1; i <= n; i++)
    {
        // Reduce all rows except the current row
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ratio = A[j][i] / A[i][i];
                for (k = 1; k <= n; k++)
                {
                    A[j][k] -= ratio * A[i][k];
                    identity[j][k] -= ratio * identity[i][k];
                }
            }
        }

        // Make the diagonal element of A to 1
        ratio = A[i][i];
        for (j = 1; j <= n; j++)
        {
            A[i][j] /= ratio;
            identity[i][j] /= ratio;
        }
    }

    // Output the inverse matrix
    printf("\nThe inverse of the matrix A is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%.2f\t", identity[i][j]);
        }
        printf("\n");
    }

    return 0;
}