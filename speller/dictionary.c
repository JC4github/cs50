// Implements a dictionary's functionality
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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
    FILE *fp = fopen(dictionary, "r"); // opens file
    if (fp == NULL)
    {
        fclose(fp);
        return false;
    }
    else
    {
        char currentWord[LENGTH + 1];
        for (int i = 0; i < 26; i++)
        {
            table[i] = malloc(sizeof(node));
            if (table[i] == NULL)
            {
                return false;
            }

            table[i]->next = NULL;
        }

        while (fscanf(fp, "%s", currentWord) != EOF)
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }

            else
            {
                wordCount++;

                strcpy(n->word, currentWord);
                n->next = NULL;

                int hashPosition = hash(n->word);
                if (table[hashPosition]->next == NULL)
                {
                    table[hashPosition]->next = n;
                }
                else
                {
                    n->next = table[hashPosition]->next;
                    table[hashPosition]->next = n;
                }
            }
        }
        return true;
    }
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
    for (int i = 0; i < 26; i++)
    {
        node *list = table[i];
        while (list != NULL)
        {
            node *tmp = list->next;
            free(list);
            list = tmp;
        }
    }
    return true;
}
