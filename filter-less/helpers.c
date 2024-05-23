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
            // Top left
            BYTE tl_red;
            BYTE tl_green;
            BYTE tl_blue;

            // Top center
            BYTE tc_red;
            BYTE tc_green;
            BYTE tc_blue;

            // Top right
            BYTE tr_red;
            BYTE tr_green;
            BYTE tr_blue;

            // Left
            BYTE left_red;
            BYTE left_green;
            BYTE left_blue;

            // Center
            BYTE center_red = image[i][j].rgbtRed;
            BYTE center_green = image[i][j].rgbtGreen;
            BYTE center_blue = image[i][j].rgbtBlue;

            // Right
            BYTE right_red;
            BYTE right_green;
            BYTE right_blue;

            // Bottom left
            BYTE bl_red;
            BYTE bl_green;
            BYTE bl_blue;

            // Bottom center
            BYTE bc_red;
            BYTE bc_green;
            BYTE bc_blue;

            // Bottom right
            BYTE br_red;
            BYTE br_green;
            BYTE br_blue;

            // Make sure the pixel exists before assigning
            if (i != 0 && j != 0)
            {
                tl_red = image[i - 1][j - 1].rgbtRed;
                tl_green = image[i - 1][j - 1].rgbtGreen;
                tl_blue = image[i - 1][j - 1].rgbtBlue;
            }

            if (i != 0)
            {
                tc_red = image[i - 1][j].rgbtRed;
                tc_green = image[i - 1][j].rgbtGreen;
                tc_blue = image[i - 1][j].rgbtBlue;
            }

            if (i != 0 && j != (width - 1))
            {
                tr_red = image[i - 1][j + 1].rgbtRed;
                tr_green = image[i - 1][j + 1].rgbtGreen;
                tr_blue = image[i - 1][j + 1].rgbtBlue;
            }

            if (j != 0)
            {
                left_red = image[i][j - 1].rgbtRed;
                left_green = image[i][j - 1].rgbtGreen;
                left_blue = image[i][j - 1].rgbtBlue;
            }

            if (j != (width - 1))
            {
                right_red = image[i][j + 1].rgbtRed;
                right_green = image[i][j + 1].rgbtGreen;
                right_blue = image[i][j + 1].rgbtBlue;
            }

            if (i != (height - 1) && j != 0)
            {
                bl_red = image[i + 1][j - 1].rgbtRed;
                bl_green = image[i + 1][j - 1].rgbtGreen;
                bl_blue = image[i + 1][j - 1].rgbtBlue;
            }

            if (i != (height - 1))
            {
                bc_red = image[i + 1][j].rgbtRed;
                bc_green = image[i + 1][j].rgbtGreen;
                bc_blue = image[i + 1][j].rgbtBlue;
            }

            if (i != (height - 1) && j != (width - 1))
            {
                br_red = image[i + 1][j + 1].rgbtRed;
                br_green = image[i + 1][j + 1].rgbtGreen;
                br_blue = image[i + 1][j + 1].rgbtBlue;
            }

            BYTE target_red;
            BYTE target_green;
            BYTE target_blue;

            if (i == 0 && j == 0)
            {
                target_red = (center_red + right_red + bc_red + br_red) / 4;
                target_green = (center_green + right_green + bc_green + br_green) / 4;
                target_blue = (center_blue + right_blue + bc_blue + br_blue) / 4;
            }
            else if (i == 0 && j == (width - 1))
            {
                target_red = (center_red + left_red + bc_red + bl_red) / 4;
                target_green = (center_green + left_green + bc_green + bl_green) / 4;
                target_blue = (center_blue + left_blue + bc_blue + bl_blue) / 4;
            }
            else if (i == (height - 1) && j == 0)
            {
                target_red = (center_red + right_red + tc_red + tr_red) / 4;
                target_green = (center_green + right_green + tc_green + tr_green) / 4;
                target_blue = (center_blue + right_blue + tc_blue + tr_blue) / 4;
            }
            else if (i == (height - 1) && j == (width - 1))
            {
                target_red = (center_red + left_red + tc_red + tl_red) / 4;
                target_green = (center_green + left_green + tc_green + tl_green) / 4;
                target_blue = (center_blue + left_blue + tc_blue + tl_blue) / 4;
            }
            else if (i == 0 && j != 0 && j != (width - 1))
            {
                target_red = (left_red + center_red + right_red + bl_red + bc_red + br_red) / 6;
                target_green = (left_green + center_green + right_green + bl_green + bc_green + br_green) / 6;
                target_blue = (left_blue + center_blue + right_blue + bl_blue + bc_blue + br_blue) / 6;
            }
            else if (i == (height - 1) && j != 0 && j != (width - 1))
            {
                target_red = (left_red + center_red + right_red + tl_red + tc_red + tr_red) / 6;
                target_green = (left_green + center_green + right_green + tl_green + tc_green + tr_green) / 6;
                target_blue = (left_blue + center_blue + right_blue + tl_blue + tc_blue + tr_blue) / 6;
            }
            else if (j == 0 && i != 0 && i != (height - 1))
            {
                target_red = (tc_red + tr_red + center_red + right_red + bc_red + br_red) / 6;
                target_green = (tc_green + tr_green + center_green + right_green + bc_green + br_green) / 6;
                target_blue = (tc_blue + tr_blue + center_blue + right_blue + bc_blue + br_blue) / 6;
            }
            else if (j == (width - 1) && i != 0 && i != (height - 1))
            {
                target_red = (tl_red + tc_red + center_red + left_red + bc_red + bl_red) / 6;
                target_green = (tl_green + tc_green + center_green + left_green + bc_green + bl_green) / 6;
                target_blue = (tl_blue + tc_blue + center_blue + left_blue + bc_blue + bl_blue) / 6;
            }
            else
            {
                target_red = (tl_red + tc_red + tr_red + left_red + center_red + right_red + bl_red + bc_red + br_red) / 9;
                target_green = (tl_green + tc_green + tr_green + left_green + center_green + right_green + bl_green + bc_green + br_green) / 9;
                target_blue = (tl_blue + tc_blue + tr_blue + left_blue + center_blue + right_blue + bl_blue + bc_blue + br_blue) / 9;
            }

            image[i][j].rgbtRed = target_red;
            image[i][j].rgbtGreen = target_green;
            image[i][j].rgbtBlue = target_blue;
        }
    }

    return;
}
