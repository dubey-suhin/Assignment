#include<stdio.h>

// dy/dx + xy =0
float dydx(float x, float y) { return (-1*x*y); }

float euler(float x0, float y0, float xf, float h){
    int n = (int)((xf - x0) / h);

    printf("x\t   y(x)\n");
    for (int i = 0; i < n; i++) {
        printf("%f  %f\n",x0,y0);

        float y1=y0 + h * dydx(x0,y0);
        float x1=x0+h;
        
        x0=x1;
        y0=y1;
    }
        printf("%f  %f\n",x0,y0);

    return y0;
}

int main()
{
    float x0 = 0, y0 = 1, xf = 0.25, h = 0.05;
    printf( "y(%f)=%f",xf,euler(x0,y0,xf,h));

    return 0;
}

