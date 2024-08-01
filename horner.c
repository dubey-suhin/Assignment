#include <stdio.h>
#define MAX_DEGREE 100
// Function to evaluate polynomial using Horner's method
double horner(double a[], int n, double x0) {
    double result = a[n];
    for (int i = 1; i <= n; i++) {
        result = a[n-i] + x0 * result ;
    }
    return result;
}

int main() {
    int deg;
    printf("Enter the degree of the polynomial (up to %d): ", MAX_DEGREE);
    scanf("%d", &deg);
    
    if (deg > MAX_DEGREE) {
        printf("Degree exceeds the maximum allowed (%d).\n", MAX_DEGREE);
        return 1;
    }
    double coeffs[deg + 1];

    printf("Enter the coefficients :\n");
    for (int i = 0; i <= deg; i++) {
        printf("Coefficient for x^%d: ", i);
        scanf("%lf", &coeffs[i]);
    }
    
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate polynomial using Horner's method
    double result = horner(coeffs, deg, x);
    printf("\nf(x)= ");
    for (int i = deg; i >=0; i--){
        printf("%.2f",coeffs[i]);
        if(i>0)
            printf("x^%d + ",i);
    }
    
    printf("\nf(%.2f) = %.2f\n", x, result);    
    return 0;
}