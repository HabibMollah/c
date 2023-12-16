#include <stdio.h>

long add(int x, int y);
double divide(int x, int y);

int main(void)
{
    int x;
    int y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("\n");
    printf("Enter the value of y: ");
    scanf("%d", &y);
    printf("\n");
    // long result = add(x, y);
    double result = divide(x, y);
    printf("%.20lf\n", result);
    return 0;
}

double divide(int x, int y)
{
    double division = (double) x / (double) y;
    return division;
}

long add(int x, int y)
{
    long sum = (long) x + (long) y;
    return sum;
}