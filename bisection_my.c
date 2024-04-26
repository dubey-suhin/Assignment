
#include<stdio.h>
#include<math.h>
float findValue(float x)
{
    return x*x*x - 4*x + 1;
}

float bisect(float x1, float x2)
{
    return (x1+x2)/2;
}


int main ()
{
    int n, i=1;
    float x1, x2,x, e;
    printf("Enter maximum no of iterations: ");
    scanf("%d",&n);

    printf("Tollerebence error: ");
    scanf("%f", &e);

    do
    {
        printf("Enter the value of x1 & x2: ");
        scanf("%f%f", &x1,&x2);
        if(findValue(x1)*findValue(x2)>0)
        {
            printf("Roots are invalid\n");
            continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n ", x1,x2);
            break;
        }

    }while(1);


    while(i<=n)
    {
        float bisect(float x1, float x2);
        x = bisect(x1,x2); //find the midpoint
        if(findValue(x)*findValue(x1)<0)
            x2 =x ; //x2 is shifted;

        else if(findValue(x)*findValue(x2)<0)
            x1=x; //x1 is shifted


        float f1 = findValue(x);
        printf("Iteration= %d      Roots=%f\tf(x)=%f\tError=%f\n ",i,x, f1,fabs(f1));

        i++;
    }
    printf("Root=%f  Total Iterations=%d",x,--i);


    return 0;
}