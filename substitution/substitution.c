#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    char lowerkey[26];
    for (int i = 0; i < 26; i++)
    {
        lowerkey[i] = argv[1][i];
    }

    printf("%s\n", lowerkey);
    printf("%c\n", argv[1][0]);
    return 0;
}