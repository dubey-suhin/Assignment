//Regular Falsi Methode

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (x*x*x-4*x+1)

int main()
{
    float x0,x1,x2,e,f0,f1,f2;
    int step=0;
    printf("Tollerable error: ");
    scanf("%f",&e);

    float lower_value=0, upper_value=100;
    for(x0=lower_value; x0<=upper_value; x0+=0.5)
    {
        f0 = f(x0);
        f1 = f(x0+0.5);
        if(f0 * f1 <0)
            break;
    }

    printf("Iteration\tx0\t\tx1\t\tx2\t\tf(x2)\t\terror\n");
    do
    {
        x2=  ((x0*f(x1)) - (x1*f(x0)))/ (f(x1) - f(x0));
        f2=f(x2);
        if(f0*f2 <0 )
            x1=x2;
        else
        x0=x2;

        step++;
        printf("%d\t\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t%4.6f\n" ,step,x0,x1,x2,f2,fabs(f2));


    }while(fabs(f2)>e);

    printf("\nThe root of the function is %4.6f after %d iterations.\n",x2,step);
    return 0;
}