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
        for (int j = 0; j < width; j++)
        {
            BYTE buffer_red = image[i][j].rgbtRed;
            BYTE buffer_green = image[i][j].rgbtGreen;
            BYTE buffer_blue = image[i][j].rgbtBlue;
            printf("BEFORE buffer_red: %i, left red: %i, right red: %i\n", buffer_red, image[i][j].rgbtRed, image[i][width - (j + 1)].rgbtRed);

            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;

            image[i][width - (j + 1)].rgbtRed = buffer_red;
            image[i][width - (j + 1)].rgbtGreen = buffer_green;
            image[i][width - (j + 1)].rgbtBlue = buffer_blue;
            printf("AFTER buffer_red: %i, left red: %i, right red: %i\n", buffer_red, image[i][j].rgbtRed, image[i][width - (j + 1)].rgbtRed);
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
