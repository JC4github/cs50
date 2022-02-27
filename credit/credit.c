#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long long cardnum = get_long("Number: ");
    char numtext[256];
    sprintf(numtext, "%lld", cardnum);

    char cardtype[];
    if (strlen(numtext) < 13 && strlen(numtext) > 16)
    {
        cardtype = "INVALID";
    }
    else
    {
        if (numtext[0] == 4)
        {
            cardtype = "VISA";
        }
        else if (numtext[0] = 5 && numtext[1] > 0 && numtext[1] < 6)
        {
            cardtype = "MASTERCARD";
        }
        else if (numtext[0] = 3 && (numtext[1] = 4 || numtext[1] = 7)
        {
            cardtype = "AMEX";
        }
        else
        {
            cardtype = "INVALID";
        }
    }


    printf("%s\n", numtext);
}