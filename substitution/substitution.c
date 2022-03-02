#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{


    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int length = strlen(argv[1]);
    else if(length != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    return 0;
}