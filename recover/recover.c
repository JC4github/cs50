#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("only input one file");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Cant open file");
        return 1;
    }

    int counter = 0;
    BYTE buffer[512];
    char *filename = malloc(4);
    FILE *img;

    while (fread(&buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, 1, 512, img);
            }
            else
            {
                fclose(img);
                img = NULL;
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, 1, 512, img);
            }
            counter++;
        }
        else if(counter > 0)
        {
            fwrite(&buffer, 1, 512, img);
        }
    }
    fclose(img);
}