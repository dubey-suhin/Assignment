#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x - 4 * x + 1);
}

float diff(float x)
{
    return (3 * x * x - 4);
}
int main()
{
    int n, i = 1;
    float x, x0, x1, x2, fx, e, f1, f2, f0;
    printf("Enter the tollerable error: ");
    scanf("%f", &e);
    do
    {
        printf("Enter Two Initial guesses: ");
        scanf("%f%f", &x1, &x2);
        // float low_val = -2 , high_val = 100;
        // for(x1= low_val; x1<= high_val; x1 += 0.5){
        //     f1 = f(x1);
        //     f2 = f(x1+0.5);
        if (f(x1) * f(x2) > 0)
        {
            printf("Invalid Value, Enter Correct value: \n");
            continue;
        }

        else
        {
            printf("The roots are lies between x1=%f and x2=%f\n", x1, x2);
            break;
        }
        //     if(f1 * f2 <0)
        //         break;
        // }

    } while (1);

    // Calculating X0
    if (fabs(f(x1)) < fabs(f(x2)))
        x0 = x1;
    else
        x0 = x2;

    printf("Iteration\tx0\tx\t f(x)\tError\n");

    do
    {
        x = x0 - (f(x0) / diff(x0));
        printf("%d\t\t%4.4f\t%4.4f\t%4.4f\t%4.4f\n", i, x0, x, f(x), fabs(f(x)));
        if (fabs(x - x0) < e)
        {
            printf("The root is x:%f\n ", x);
            return 0;
        }
        printf("Root is x: %f\n", x);
        x0 = x;

        i++;

    } while (fabs(f(x) < e));

    printf("The root IS X: %f", x);
    return 0;
}