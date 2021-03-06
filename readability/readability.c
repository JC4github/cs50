#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;

//loop through array finding things
    for (int i = 0; i < length; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }

//doing the math of coleman liau index
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

//printing results
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}