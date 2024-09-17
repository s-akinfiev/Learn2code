#include <stdio.h>
#include <math.h>

double fun(double x);

int main(void)
{
    double x = 0;
    char term = ' ';
    if (scanf("%lf%c", &x, &term) == 2 && term == '\n')
    {
        if (isnan(fun(x)) != 1)
        { 
            printf("%.1f", fun(x));
        }
        else
        {
            printf("n/a");
        }
    }
    else
    {
        printf("n/a");
    }
    return 0;
}

double fun(double x)
{ 
    return (7e-3 * pow(x, 4) + ((22.8 * cbrt(x) - 1e3) * x + 3) / (x * x / 2) - x * pow((10. + x), (2. / x)) - 1.01);
}