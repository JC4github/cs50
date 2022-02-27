#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    while (true)
    {
        height = get_int("Height: ");
        if (height > 0 && height <= 8)
        {
            break;
        }
    }

    int numspace = height - 1;

    for (int i = 1; i <= height; i++)
    {
        int spaces = numspace;
        int blocks = i;
        while (spaces > 0)
        {
            printf(" ");
            spaces--;
        }
        while (blocks > 0)
        {
            printf("#");
            blocks--;
        }
        printf("  ");
        while (blocks > 0)
        {
            printf("#");
            blocks--;
        }
        numspace--;
        printf("\n");
    }
}