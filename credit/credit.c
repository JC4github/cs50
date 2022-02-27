#include <cs50.h>
#include <stdio.h>
#include <string.h>

int checkforvalid(int arr[], int length)
{
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 1; i < length ; i += 2)
    {
        if (arr[i] * 2 >= 10)
        {
            sum1++;
            sum1 = sum1 + (arr[i] * 2 - 10);
        }
        else
        {
            sum1 = sum1 + (arr[i] * 2);
        }
    }
    for (int i = 0; i < length ; i += 2)
    {
        sum2 = sum2 + (arr[i]);
    }
    int sum = sum1 + sum2;
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

    char numtext[256];
    sprintf(numtext, "%lld", cardnum);
    int size = strlen(numtext);

    int array[size];
    int i = 0;
    long long num = cardnum;
    while (num > 0)
    {
        array[i] = num % 10; //creates flipped array
        num = num / 10;
        ++i;
    }

    if (size < 13 || size > 16)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        if (array[size - 1] == 4)
        {
            if (checkforvalid(array, size) == 1)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else if (array[size - 1] == 5 && array[size - 2] > 0 && array[size - 2] < 6)
        {
            if (checkforvalid(array, size) == 1)
            {
                printf("MASTERCARD\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else if (array[size - 1] == 3 && (array[size - 2] == 4 || array[size - 2] == 7))
        {
            if (checkforvalid(array, size) == 1)
            {
                printf("AMEX\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    return 0;
}