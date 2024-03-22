#include <stdio.h>

int main(void)
{
    int numbers[8] = {2, 4, 1, 0, 7, 5, 6, 5};

    int min = numbers[0];
    int min_index = 0;
    // Implement selection sort
    for (int i = 0; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
        {
            if (numbers[j] < min)
            {
                min = numbers[j];
                min_index = j;
            }
        }
        numbers[min_index] = numbers[i];
        numbers[i] = min;
        min = numbers[i + 1];
        min_index = i + 1;
    }

    // Print the numbers
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}