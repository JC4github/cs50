#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE red;
    BYTE green;
    BYTE blue;
    BYTE avg;

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;
            avg = round((red + blue + green) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half;
    if (width % 2 == 1)
    {
        half = width - (int)(width/2);
    }
    else
    {
        half = width/2;
    }

    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE s[8];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                if (i == 0)
                {
                    BYTE red = 0;
                    BYTE green;
                    BYTE blue;

                    s[0] = image[i][j + 1];
                    s[1] = image[i + 1][j + 1];
                    s[2] = image[i + 1][j ];
                    for (int k = 0; k < 3; k++)
                    {
                        BYTE red = s[k].rgbtRed
                    }
                    image[i][j].rgbtRed = round(s1.rgbtRed + s2.rgbtRed + s3.rgbtRed + )
                }
                else if (i = height - 1)
                {

                }
                else
                {

                }
            }
            else if (j == width - 1)
            {
                if (i == 0)
                {
                }
                else if (i = height - 1)
                {
                }
                else
                {
                }
            }
            else
            {
                if (i == 0)
                {
                }
                else if (i = height - 1)
                {
                }
                else
                {
                }
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
