#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s;
    s = malloc(sizeof(char) * 50);
    printf("s: ");
    scanf("%s", s);
    printf("Length of %s is %lu\n", s, strlen(s));
    free(s);
}