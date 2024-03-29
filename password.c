// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool has_upper = false;
    bool has_lower = false;
    bool has_number = false;
    bool has_symbol = false;

    int length = strlen(password);
    for (int i = 0; i < length; i++)
    {
       char current_char = password[i];
       if (isalnum(current_char))
       {
          if (isalpha(current_char))
          {
            if (islower(current_char)) has_lower = true;
            if (isupper(current_char)) has_upper = true;
          }
          else if (isdigit(current_char))
          { 
            has_number = true;
          }
       }
       else
       {
          has_symbol = true;
       }
    }
    return has_lower && has_upper && has_symbol && has_number;
}
