#include <stdio.h>
#include <stdlib.h>
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

    while (fread(buffer, 1, 512, file) == 512)
    {
    }
}