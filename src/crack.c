#include <stdio.h>
#

int main()
{
    double x = 0, y = 0;
    char term = ' ';
    if (scanf("%lf%lf%c", &x, &y, &term) == 3 && term == '\n')
    {
    if (((x * x) + (y * y)) < 25)
        printf("GOTCHA");
    else
        printf("MISS");
    }
    else
        printf("n/a");
    return 0;
}