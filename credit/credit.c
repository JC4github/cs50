#include <cs50.h>
#include <stdio.h>
#include <string.h>

int checkforvalid(int arr[], int length)
{
    int sum;
    for (int i = 1; i < length ; i+=2)
    {
        sum = sum + (arr[i]*2);
    }
    for (int i = 0; i < length ; i+=2)
    {
        sum = sum + (arr[i]);
    }
    if (sum % 10 > 0)
    {
        return 2; //invalid
    }
    else
    {
        return 1; //valid
    }
}


int main(void)
{
    long long cardnum = get_long("Number: ");

    int array[25];
    while (cardnum > 0)
    {
        int num = cardnum;
        int i = 0;
        array[i] = num % 10; //creates flipped array
        num = num / 10;
        ++i;
    }

    char numtext[256];
    sprintf(numtext, "%lld", cardnum);
    int size = strlen(numtext);

    char cardtype[10];

    if (size < 13 || size > 16)
    {
        strcpy(cardtype, "INVALID");
        return printf("%s\n", cardtype);
    }
    else
    {
        if (array[0] == 4)
        {
            if (checkforvalid(array, size) == 1)
            {
                strcpy(cardtype, "VISA");
                return printf("%s\n", cardtype);
            }
            else
            {
                strcpy(cardtype, "INVALID");
                return printf("%s\n", cardtype);
            }
        }
        else if (array[0] == 5 && array[1] > 0 && array[1] < 6)
        {
            if (checkforvalid(array, size) == 1)
            {
                strcpy(cardtype, "MASTERCARD");
                return printf("%s\n", cardtype);
            }
            else
            {
                strcpy(cardtype, "INVALID");
                return printf("%s\n", cardtype);
            }
        }
        else if (array[0] == 3 && (array[1] == 4 || array[1] == 7))
        {
            if (checkforvalid(array, size) == 1)
            {
                strcpy(cardtype, "AMEX");
                return printf("%s\n", cardtype);
            }
            else
            {
                strcpy(cardtype, "INVALID");
                return printf("%s\n", cardtype);
            }
        }
        else
        {
            strcpy(cardtype, "INVALID");
            return printf("%s\n", cardtype);
        }
    }
    return 0;
}