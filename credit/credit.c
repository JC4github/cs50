#include <cs50.h>
#include <stdio.h>
#include <string.h>

string checkforvalid(int arr[], int length)
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
        return "INVALID";
    }
    else
    {
        return 0;
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
    int length = strlen(numtext);
    
    char cardtype[10];

    if (length < 13 || length > 16)
    {
        strcpy(cardtype, "INVALID");
        return printf("%s\n", cardtype);
    }
    else
    {
        if (array[0] == 4)
        {
            strcpy(cardtype, "VISA");
        }
        else if (array[0] == 5 && array[1] > 0 && array[1] < 6)
        {
            strcpy(cardtype, "MASTERCARD");
        }
        else if (array[0] == 3 && (array[1] == 4 || array[1] == 7))
        {
            strcpy(cardtype, "AMEX");
        }
        else
        {
            strcpy(cardtype, "INVALID");
            return printf("%s\n", cardtype);
        }
    }



    strcpy(cardtype, checkforvalid(array, length));
    return printf("%s\n", cardtype);
}