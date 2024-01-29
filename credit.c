#include "cs50.h"
#include <stdio.h>

int get_num_length(long);
int luhn_algorithm_checksum(long);
int get_nth_last_digit(long long card_num, int n);
int sum_digits(int);
string determine_type(long);
int get_first_digit(long);
int get_first_two_digits(long);

int main(void)
{
    long card_num = get_long("Enter credit card number: \n");

    if (luhn_algorithm_checksum(card_num))
    {
        printf("%s", determine_type(card_num));
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_num_length(long num)
{
    int length = 0;
    while (num >= 1)
    {
        num /= 10;
        length++;
    }
    return length;
}

int get_nth_last_digit(long long card_num, int n)
{
    int last_digit = 0;
    while (n > 0)
    {
        last_digit = card_num % 10;
        card_num /= 10;
        n--;
    }
    return last_digit;
}

int sum_digits(int num)
{
    int result = 0;
    while (num >= 1)
    {
        result += get_nth_last_digit(num, 1);
        num /= 10;
    }
    return result;
}

int luhn_algorithm_checksum(long card_num)
{
    int card_num_length = get_num_length(card_num);
    int iterations = card_num_length / 2;
    int sum_of_product_digits = 0;
    int nth_to_last = 2;
    for (int i = 0; i < iterations; i++)
    {
        int product = get_nth_last_digit(card_num, nth_to_last) * 2;
        sum_of_product_digits += sum_digits(product);
        nth_to_last += 2;
    }

    nth_to_last = 1;
    iterations = card_num_length % 2 == 0 ? iterations : iterations + 1;
    int sum_of_other_digits = 0;
    for (int i = 0; i < iterations; i++)
    {
        sum_of_other_digits += get_nth_last_digit(card_num, nth_to_last);
        nth_to_last += 2;
    }
    int total_sum = sum_of_product_digits + sum_of_other_digits;

    return total_sum % 10 == 0;
}

int get_first_digit(long card_num)
{
    int iterations = get_num_length(card_num) - 1;
    for (int i = 0; i < iterations; i++)
    {
        card_num /= 10;
    }
    return card_num;
}

int get_first_two_digits(long card_num)
{
    int iterations = get_num_length(card_num) - 2;
    for (int i = 0; i < iterations; i++)
    {
        card_num /= 10;
    }
    return card_num;
}

string determine_type(long card_num)
{
    int card_num_length = get_num_length(card_num);
    int first_digit = get_first_digit(card_num);
    int first_two_digit = get_first_two_digits(card_num);

    if ((card_num_length == 13 || card_num_length == 16) && first_digit == 4)
        return "VISA\n";

    if (card_num_length == 15 && (first_two_digit == 34 || first_two_digit == 37))
        return "AMEX\n";

    if (card_num_length == 16 &&
        (first_two_digit == 51 || first_two_digit == 52 || first_two_digit == 53 || first_two_digit == 54 || first_two_digit == 55))
        return "MASTERCARD\n";

    return "INVALID\n";
}
