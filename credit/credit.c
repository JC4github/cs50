#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnum = get_long("Number: ");

    char numtext[] = (char)cardnum;

    printf("%s", numtext);
}