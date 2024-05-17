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
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
