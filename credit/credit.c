#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long cardnum = get_long("Number: ");
    char numtext[256];
    sprintf(numtext, "%lld", cardnum);

    char cardtype[];
    if (numtext[0] == 4)
    {
        cardtype = "Visa"
    }
    else if (numtext[0] = 5)
    {
        cardtype = 
    }

    printf("%s\n", numtext);
}