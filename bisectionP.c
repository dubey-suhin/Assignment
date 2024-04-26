#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (x * x * x - 4 * x + 1)

int main() {
    float x0, x1, x2, e, f0, f1, f2;
    int step = 0;
    
    // Define the interval where the root might lie
    float lower_bound = 0; // Adjust these bounds as per your requirement
    float upper_bound = 10.0;
    
    // Specify the desired tolerance error
    printf("Enter tolerable error :: ");
    scanf("%f", &e);

    // Generate initial guesses within the specified interval
    for (x0 = lower_bound; x0 <= upper_bound; x0 += 0.5) {
        f0 = f(x0);
        f1 = f(x0 + 0.5);
        if (f0 * f1 < 0)
            break;
    }
    
    printf("Initial guess: x0 = %f, x1 = %f\n", x0, x0 + 0.5);
    
    // Bisection method to find the root
    printf("Iteration\t\tx0\t\tx1\t\tx2\t\tf(x2)\t\terror\n");
    do {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        if (f0 * f2 < 0)
            x1 = x2;
        else
            x0 = x2;
        step++;
        printf("%d\t\t\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t%4.6f\n", step, x0, x1, x2, f2, fabs(f2));
    } while (fabs(f2) > e);

    printf("\nThe approximate root is :: %f", x2);

    return 0;
}
