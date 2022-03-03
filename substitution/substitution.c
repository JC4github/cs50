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
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if ((argv[1][i] < 'A' || argv[1][i] > 'Z') && (argv[1][i] < 'a' || argv[1][i] > 'z'))
            {
                printf("Key must only contain alphabet characters.\n");
                return 1;
            }
        }
    }

        // make two key, one all cap, one all lower
    char lowerkey[26];
    char higherkey[26];
    for (int i = 0; i < 26; i++)
    {
        lowerkey[i] = tolower(argv[1][i]);
        higherkey[i] = toupper(argv[1][i]);
    }

    //checking for dups
    int total = 0;
    for (int i = 0; i < 26; i++)
    {
        total = total + higherkey[i];
    }
        string userIn = get_string("plaintext: ");
    int length = strlen(userIn);

    for (int i = 0; i < length; i++)
    {
        if (userIn[i] >= 'A' && userIn[i] <= 'Z')
        {
            int pos = userIn[i] - 'A';
            userIn[i] = higherkey[pos];
        }
        else if (userIn[i] >= 'a' && userIn[i] <= 'z')
        {
            int pos = userIn[i] - 'a';
            userIn[i] = lowerkey[pos];
        }
    }

    printf("ciphertext: %s\n", userIn);
    printf("%d\n", total);
    return 0;
}