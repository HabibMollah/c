#include <stdio.h>

#define LENGTH 8

int main(void)
{
    int numbers[LENGTH] = {0, 1, 2, 4, 5, 5, 6, 7};

    for (int i = 0; i < LENGTH; i++)
    {
        int swaps = 0;
        for (int j = 0; j < LENGTH - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                // Swap the 1st item with the 2nd
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swaps++;
            }
        }
        if (swaps == 0)
            break;
    }

    // Print the numbers
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}