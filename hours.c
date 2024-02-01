#include "cs50.h"
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);
float sum(int num[], int num_count);
float average(float sum, int num_count);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    if(output == 'T')
    {
        return sum(hours, weeks);
    }
    return average(sum(hours, weeks), weeks);
}

float sum(int num[], int num_count)
{
    float sum = 0;
    for (int i = 0; i < num_count; i++)
    {
        sum += num[i];
    }
    return sum;
}

float average(float sum, int num_count)
{
    return sum / num_count;
}