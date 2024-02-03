#include "cs50.h"
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    int length = strlen(message);
    for (int i = 0; i < length; i++)
    {
        int message_char_ascii_number = (int) message[i];
        int bits_of_a_char[8];
        // Create a byte with all bits set to 0
        for (int j = 0; j < 8; j++)
        {
            bits_of_a_char[j] = 0;
        }
        // Store the binary of the ascii number
        int index = 7;
        while (message_char_ascii_number > 0)
        {
            // printf("Index: %d\n", index);
            // printf("remainder of 2: %d\n", message_char_ascii_number % 2);
            bits_of_a_char[index] = message_char_ascii_number % 2;
            // printf("before dividing with 2: %d\n", message_char_ascii_number);
            message_char_ascii_number /= 2;
            // printf("after dividing with 2: %d\n", message_char_ascii_number);
            index--;
            // printf("\n");
        }
        for (int j = 0; j < 8; j++)
        {
            print_bulb(bits_of_a_char[j]);
        }
        printf("\n");

    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}