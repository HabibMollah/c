#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_sentences(string paragraph);
int count_words(string paragraph);
int count_letters(string paragraph);
float get_L_value(int letters, int words);
float get_S_value(int sentences, int words);

int main()
{
    string paragraph = get_string("Text: ");
    int sentences = count_sentences(paragraph);
    int words = count_words(paragraph);
    int letters = count_letters(paragraph);
    int grade = round(0.0588 * get_L_value(letters, words) - 0.296 * get_S_value(sentences, words) - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int count_sentences(string paragraph)
{
    int count = 0;
    int i = 0;
    int paragraph_length = strlen(paragraph);
    while (i < paragraph_length)
    {
        if (paragraph[i] == '.' ||
            paragraph[i] == '!' ||
            paragraph[i] == '?')
        {
            count++;
        }
        i++;
    }
    return count;
}

int count_words(string paragraph)
{
    int count = 1;
    int i = 0;
    int paragraph_length = strlen(paragraph);
    while (i < paragraph_length)
    {
        if (paragraph[i] == ' ' && paragraph[i - 1] && paragraph[i + 1])
        {
            count++;
        }
        i++;
    }
    return count;
}

int count_letters(string paragraph)
{
    int count = 0;
    int i = 0;
    int paragraph_length = strlen(paragraph);
    while (i < paragraph_length)
    {
        char current_char = tolower(paragraph[i]);

        if (current_char == 'a' || current_char == 'b' || current_char == 'c' || current_char == 'd' || current_char == 'e' || current_char == 'f' || current_char == 'g' || current_char == 'h' || current_char == 'i' || current_char == 'j' || current_char == 'k' || current_char == 'l' || current_char == 'm' || current_char == 'n' || current_char == 'o' || current_char == 'p' || current_char == 'q' || current_char == 'r' || current_char == 's' || current_char == 't' || current_char == 'u' || current_char == 'v' || current_char == 'w' || current_char == 'x' || current_char == 'y' || current_char == 'z')
        {
            count++;
        }
        i++;
    }
    return count;
}

float get_L_value(int letters, int words)
{
    return (float)letters / words * 100;
}

float get_S_value(int sentences, int words)
{
    return (float)sentences / words * 100;
}