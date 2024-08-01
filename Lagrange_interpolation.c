#include<stdio.h>

int main()
{
    int n;
    printf("Enter No. of point :");
    scanf("%d",&n);

    float sum=0.0,prod,p,x[n],fx[n];
    printf("Enter value of Points(x) and Their f(x) value :\n x  f(x)\n");
    for (int i = 0; i < n; i++){
        scanf("%f %f",&x[i],&fx[i]);
    }
    printf("Enter the value which will be found :");
    scanf("%f",&p);

    for (int i = 0; i < n; i++){
        prod=1;
        for (int j = 0; j < n; j++){
            if(i!=j){
                prod *= ((p-x[j])/(x[i]-x[j]));
            }
        }
        sum += (prod*fx[i]);
    }
    
    printf("\nf(%f)=%f\n",p,sum);
    
    return 0;
}
