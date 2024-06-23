// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

FILE *dict_file = NULL;
unsigned int word_count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int idx = hash(word);
    node *ptr = table[idx];
    while (ptr != NULL)
    {
        if (ptr->word == word)
            return true;
        ptr = ptr->next;
    }

    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    dict_file = fopen(dictionary, "r");
    if (dict_file != NULL)
    {
        char buffer;
        char word_buffer[LENGTH + 1];
        int idx = 0;
        while (fread(&buffer, sizeof(char), 1, dict_file))
        {
            if (buffer == '\n')
            {
                word_buffer[idx] = '\0';
                word_count++;
                idx = 0;
            }
            else
            {
                word_buffer[idx] = buffer;
                idx++;
            }
        }
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (dict_file != NULL)
        return word_count;
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return true;
}
