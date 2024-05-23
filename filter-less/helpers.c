#include "helpers.h"
#include <stdio.h>

#define SHADE_COUNT 256

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE shades_of_gray[SHADE_COUNT];
    BYTE shade = 0x00;
    for (int i = 0; i < SHADE_COUNT; i++)
    {
        shades_of_gray[i] = shade;
        shade++;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE average_of_rgb = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = shades_of_gray[average_of_rgb];
            image[i][j].rgbtGreen = shades_of_gray[average_of_rgb];
            image[i][j].rgbtBlue = shades_of_gray[average_of_rgb];
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE original_red = image[i][j].rgbtRed;
            BYTE original_green = image[i][j].rgbtGreen;
            BYTE original_blue = image[i][j].rgbtBlue;

            BYTE sepiaRed = 0.393 * original_red + 0.769 * original_green + 0.189 * original_blue;
            BYTE sepiaGreen = 0.349 * original_red + 0.686 * original_green + 0.168 * original_blue;
            BYTE sepiaBlue = 0.272 * original_red + 0.534 * original_green + 0.131 * original_blue;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            BYTE buffer_red = image[i][j].rgbtRed;
            BYTE buffer_green = image[i][j].rgbtGreen;
            BYTE buffer_blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;

            image[i][width - (j + 1)].rgbtRed = buffer_red;
            image[i][width - (j + 1)].rgbtGreen = buffer_green;
            image[i][width - (j + 1)].rgbtBlue = buffer_blue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE tl_red = image[i - 1][j - 1].rgbtRed;
            BYTE tl_green = image[i - 1][j - 1].rgbtGreen;
            BYTE tl_blue = image[i - 1][j - 1].rgbtBlue;

            BYTE tc_red = image[i - 1][j].rgbtRed;
            BYTE tc_green = image[i - 1][j].rgbtGreen;
            BYTE tc_blue = image[i - 1][j].rgbtBlue;

            BYTE tr_red = image[i - 1][j + 1].rgbtRed;
            BYTE tr_green = image[i - 1][j + 1].rgbtGreen;
            BYTE tr_blue = image[i - 1][j + 1].rgbtBlue;

            BYTE left_red = image[i][j - 1].rgbtRed;
            BYTE left_green = image[i][j - 1].rgbtGreen;
            BYTE left_blue = image[i][j - 1].rgbtBlue;

            BYTE center_red = image[i][j].rgbtRed;
            BYTE center_green = image[i][j].rgbtGreen;
            BYTE center_blue = image[i][j].rgbtBlue;

            BYTE right_red = image[i][j + 1].rgbtRed;
            BYTE right_green = image[i][j + 1].rgbtGreen;
            BYTE right_blue = image[i][j + 1].rgbtBlue;

            BYTE bl_red = image[i + 1][j - 1].rgbtRed;
            BYTE bl_green = image[i + 1][j - 1].rgbtGreen;
            BYTE bl_blue = image[i + 1][j - 1].rgbtBlue;

            BYTE bc_red = image[i + 1][j].rgbtRed;
            BYTE bc_green = image[i + 1][j].rgbtGreen;
            BYTE bc_blue = image[i + 1][j].rgbtBlue;

            BYTE br_red = image[i + 1][j + 1].rgbtRed;
            BYTE br_green = image[i + 1][j + 1].rgbtGreen;
            BYTE br_blue = image[i + 1][j + 1].rgbtBlue;
        }
    }

    return;
}
