#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y);

int main(void)
{
    int num1 = 1;
    int num2 = 2;

    printf("Before swap: %i %i\n", num1, num2);
    swap(&num1, &num2);
    printf("After swap: %i %i\n", num1, num2);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}