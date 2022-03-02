#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < length; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'a'))
        {
            letters++;
        }
        else if(text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }

    printf("%d %d %d\n", words, sentences, letters);
    return 0;
}