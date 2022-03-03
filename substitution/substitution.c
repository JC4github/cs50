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

    
    for (int i = 0; i < 26, i++)
    {

    }

    char c = argv[1][0];
    string lowerkey[26];
    lowerkey[0] = tolower(c);
    printf("%s\n", lowerkey);
    printf("%c\n", argv[1][0]);
    return 0;
}