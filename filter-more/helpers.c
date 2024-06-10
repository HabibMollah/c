#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int number_of_shades = 256;
    int shades[number_of_shades];
    for (int i = 0; i < number_of_shades; i++)
    {
        shades[i] = i;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE average =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = shades[average];
            image[i][j].rgbtGreen = shades[average];
            image[i][j].rgbtBlue = shades[average];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            BYTE temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][width - (j + 1)].rgbtRed = temp;

            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
            image[i][width - (j + 1)].rgbtGreen = temp;

            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;
            image[i][width - (j + 1)].rgbtBlue = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j].rgbtRed = image[i][j].rgbtRed;
            image_copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            image_copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average_red = 0;
            float average_green = 0;
            float average_blue = 0;
            float count = 0;
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        average_red += image_copy[k][l].rgbtRed;
                        average_green += image_copy[k][l].rgbtGreen;
                        average_blue += image_copy[k][l].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(average_red / count);
            image[i][j].rgbtGreen = round(average_green / count);
            image[i][j].rgbtBlue = round(average_blue / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j].rgbtRed = image[i][j].rgbtRed;
            image_copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            image_copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    int gx_matrix[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy_matrix[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gx_red = 0, gy_red = 0, gx_green = 0, gy_green = 0, gx_blue = 0, gy_blue = 0;

            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        int row_idx = (k - i) + 1;
                        int column_idx = (l - j) + 1;
                        gx_red += image_copy[k][l].rgbtRed * gx_matrix[row_idx][column_idx];
                        gy_red += image_copy[k][l].rgbtRed * gy_matrix[row_idx][column_idx];
                        gx_green += image_copy[k][l].rgbtGreen * gx_matrix[row_idx][column_idx];
                        gy_green += image_copy[k][l].rgbtGreen * gy_matrix[row_idx][column_idx];
                        gx_blue += image_copy[k][l].rgbtBlue * gx_matrix[row_idx][column_idx];
                        gy_blue += image_copy[k][l].rgbtBlue * gy_matrix[row_idx][column_idx];
                    }
                }
            }
            int red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
            int green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));

            image[i][j].rgbtRed = red > 255 ? 255 : red;
            image[i][j].rgbtGreen = green > 255 ? 255 : green;
            image[i][j].rgbtBlue = blue > 255 ? 255 : blue;
        }
    }
    return;
}
