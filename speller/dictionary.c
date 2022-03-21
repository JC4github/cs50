// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// num of words
int wordCount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashPosition = hash(word);

    for (node *tmp = table[hashPosition]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *fp = fopen(dictionary, "r"); //opens file
    if (fp == NULL)
    {
        fclose(fp);
        return false;
    }

    string currentWord = NULL;
    while (fscanf(fp, "%s", currentWord) != EOF)
    {
        fscanf(fp, "%s", currentWord);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        wordCount++;

        strcpy(n->word, currentWord);
        n->next = NULL;

        unsigned int hashPosition = hash(currentWord);

        if (table[hashPosition]->next == NULL)
        {
            table[hashPosition]->next = n;
        }
        else
        {
            n->next = table[hashPosition]->next;
            table[hashPosition]->next = n;
        }

        free(n);
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
