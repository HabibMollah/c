#include "cs50.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string phone;
} person;

int main(void)
{
    person people[2];
    people[0].name = "David";
    people[0].phone = "+123-456-7890";

    people[1].name = "Carter";
    people[1].phone = "+098-765-432-1";

    string search = get_string("Find a phone number: ");

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, search) == 0)
        {
            printf("Found: %s\n", people[i].phone);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}