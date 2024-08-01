#include <stdio.h>

int main(){
    int n, i = 0;
    printf("Enter No. of point :");
    scanf("%d", &n);

    float sum = 0.0, sum1 = 0.0, p, x0, xn, h, fx[n];

    printf("Enter Lower Limit Of Integration : ");
    scanf("%f", &x0);
    printf("Enter Upper Limit Of Integration : ");
    scanf("%f", &xn);

    h = (xn - x0) / (n - 1);

    printf("Enter value of Points(x) and Their f(x) value :\n");
    for (int i = 0; i < n; i++){
        printf("f(%f) :", (x0 + i * h));
        scanf("%f", &fx[i]);
    }

    if (n % 2 == 0)
        sum += ((h / 2) * (fx[i] + fx[++i])); // Trapezoidal 

    // Simpson 1/3rd
    sum1 += (fx[i] + fx[n - 1]);
    for (int j = i + 1; j < (n - 1); j += 2)
        sum1 += (4 * fx[j]);

    for (int j = i + 2; j < (n - 1); j += 2)
        sum1 += (2 * fx[j]);

    sum += ((h / 3) * sum1);
    printf("Approximate Integration is %f", sum);

    return 0;
}
