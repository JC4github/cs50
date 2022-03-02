#include <cs50.h>
#include <stdio.h>
#include <string>

int main(int argc, string argv[])
{
    int length = strlen(argv);

    if(argc != 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else (length != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
}