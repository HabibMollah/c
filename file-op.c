#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./file-op filename\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Couldn't create file\n");
        fclose(file);
        return 2;
    }

    char *str = malloc(sizeof(char) * 44);
    while (fread(str, 44, 1, file))
    {
        printf("%s", str);
    }

    free(str);
    fclose(file);
    return 0;
}