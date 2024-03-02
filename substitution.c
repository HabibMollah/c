#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string tolower_string(string chars);
string toupper_string(string chars);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    int key_length = strlen(key);
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int j = 0; j < key_length; j++)
        {
            if (i != j)
            {
                if (key[i] == key[j])
                {
                    printf("Key must not contain duplicate characters.\n");
                    return 1;
                }
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    int plaintext_length = strlen(plaintext);

    for (int i = 0; i < plaintext_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
                plaintext[i] = (toupper_string(key))[plaintext[i] - 65];
            if (islower(plaintext[i]))
                plaintext[i] = (tolower_string(key))[plaintext[i] - 97];
        }
    }
    printf("ciphertext: %s\n", plaintext);
}

string tolower_string(string chars)
{
    for (int i = 0, length = strlen(chars); i < length; i++)
    {
        chars[i] = tolower(chars[i]);
    }
    return chars;
}

string toupper_string(string chars)
{
    for (int i = 0, length = strlen(chars); i < length; i++)
    {
        chars[i] = toupper(chars[i]);
    }
    return chars;
}