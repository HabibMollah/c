#include <stdio.h>

int get_size(void);
void print_bricks(int size);

int main(void) 
{
    // get size of bricks
    int n = get_size();
    printf("%d\n", n);
    // print bricks
    print_bricks(n);
    return 0;
}

int get_size(void)
{
    int n;
    do
    {
    printf("Enter the size: ");
    scanf("%d", &n);
    }
    while (n < 1);
    return n;
}

void print_bricks(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < size; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}
