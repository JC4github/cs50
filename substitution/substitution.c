#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int length = strlen(argv[1]);

    if(argc != 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if(length != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    return 0;
}