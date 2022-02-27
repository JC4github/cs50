#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnum = get_long("Number: ");

    char numtext[256];
    sprintf(numtext, "%long", cardnum);

    printf("%s", numtext);
}