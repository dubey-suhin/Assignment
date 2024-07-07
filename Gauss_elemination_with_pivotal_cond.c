#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    /* Inputs */
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    /* Reading Augmented Matrix */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Applying Gauss Elimination */
    for (i = 1; i <= n - 1; i++) {
        /* Pivotal Condensation */
        int maxRow = i;
        float maxVal = a[i][i];
        for (int p = i + 1; p <= n; p++) {
            if (a[p][i] > maxVal) {
                maxVal = a[p][i];
                maxRow = p;
            }
        }

        
        if (maxRow != i) {
            /* Swap rows */
            for (int l = 1; l <= n + 1; l++) {
                float temp = a[i][l];
                a[i][l] = a[maxRow][l];
                a[maxRow][l] = temp;
            }
            printf("\nSwapping rows %d and %d:\n", i, maxRow);
            for (int m = 1; m <= n; m++) {
                for (int l = 1; l <= n + 1; l++) {
                    printf("%.2f\t", a[m][l]);
                }
                printf("\n");
            }
        }

        for (j = i + 1; j <= n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 1; k <= n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }

        printf("\nIntermediate Matrix after Step %d:\n", i);
        for (int m = 1; m <= n; m++) {
            for (int l = 1; l <= n + 1; l++) {
                printf("%.2f\t", a[m][l]);
            }
            printf("\n");
        }
    }

    /* Obtaining Solution by Back Substitution */
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i >= 1; i--) {
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }

    return 0;
}
