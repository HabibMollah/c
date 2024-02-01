// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include "cs50.h"
#include <stdio.h>

string replace(string word);
int string_length(string word);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    printf("%s\n", replace(argv[1]));
}

string replace(string word)
{
    for (int i = 0, length = string_length(word); i < length; i++)
    {
        switch(word[i])
        {
            case 'a':
            word[i] = '6';
            break;

            case 'e':
            word[i] = '3';
            break;

            case 'i':
            word[i] = '1';
            break;

            case 'o':
            word[i] = '0';
            break;

            default:
            word[i] = word[i];
        }
    }
    return word;
}

int string_length(string word)
{
    int length = 0;
    while (word[length] != '\0')
    {
        length++;
    }
    return length;
}
