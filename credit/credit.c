#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long cardnum = get_long("Number: ");
    char numtext[256];
    sprintf(numtext, "%lld", cardnum);
    if (numtext[0] == 4)

    printf("%s\n", numtext);
}