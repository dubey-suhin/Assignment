#include<stdio.h>
#include<math.h>

float f(float x)
{
    return x*x*x + x*x -1; //x^3+x^2-1
}

float g(float x)
{
    return pow((x+1), -0.5); //1/(x+1)^(1/2)
}

int main()
{
    float x0,x1,e;
    int n,i;
    printf("Enter tollerable error: ");
    scanf("%f",&e);

    printf("Enter the inital guess: ");
    scanf("%f", &x0);

    printf("No of iterations: ");
    scanf("%d", &n);

    x1 = g(x0);
    for(i=1 ; i<=n; i++)
    {
        x0 = x1;
        x1 = g(x0);

        if(fabs((x1-x0)/x1) <= e)
        {
            printf("The root of the equation and the no of iteration is: %f %d", x1,i);
            return 0;
        }
    }
    printf("The roots doesnot exists: ");

    return 0;
}