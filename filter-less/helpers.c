#include "helpers.h"
#include <math.h>
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
            BYTE average_of_rgb =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / (float)3);
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

            int sepia_red_result = round(0.393 * original_red + 0.769 * original_green + 0.189 * original_blue);
            int sepia_green_result = round(0.349 * original_red + 0.686 * original_green + 0.168 * original_blue);
            int sepia_blue_result = round(0.272 * original_red + 0.534 * original_green + 0.131 * original_blue);

            BYTE sepia_red = sepia_red_result > 255 ? 255 : sepia_red_result;
            BYTE sepia_green = sepia_green_result > 255 ? 255 : sepia_green_result;
            BYTE sepia_blue = sepia_blue_result > 255 ? 255 : sepia_blue_result;

            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
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
    RGBTRIPLE copy[height][width];
    // Copy the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    // Read from the copy, calculate the average, write to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0, green = 0, blue = 0;
            float count = 0;
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)

                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(red / count);
            image[i][j].rgbtGreen = round(green / count);
            image[i][j].rgbtBlue = round(blue / count);
        }
    }
}
