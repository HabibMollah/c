#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char get_cipher_char(char current_char, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!(isdigit(argv[1][i])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    if ((argv[1][0] != '0' && key == 0))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        plaintext[i] = get_cipher_char(plaintext[i], key);
    }
    printf("ciphertext: %s\n", plaintext);
}

char get_cipher_char(char current_char, int key)
{

    if (!(isalpha(current_char)))
    {
        return current_char;
    }
    else
    {
        if (isupper(current_char))
        {
            current_char = current_char + key;
            while (current_char > 90)
            {
                current_char = 65 + (current_char - 90) - 1;
            }
            return current_char;
        }

        if (islower(current_char))
        {

            int cipher_char_code = (int)current_char + key;
            while (cipher_char_code > 122)
            {
                cipher_char_code = 97 + (cipher_char_code - 122) - 1;
            }
            char cipher_char = (char)cipher_char_code;
            return cipher_char;
        }

        return current_char;
    }
}
