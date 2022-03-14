#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE red;
    BYTE green;
    BYTE blue;
    BYTE avg;

    for (int i = 0; i < height; i++)
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
        half = width - (int)(width / 2);
    }
    else
    {
        half = width / 2;
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
    RGBTRIPLE tempimg[height][width];
    RGBTRIPLE s[9];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                if (i == 0)
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j + 1];
                    s[1] = image[i + 1][j + 1];
                    s[2] = image[i + 1][j];
                    s[3] = image[i][j];

                    for (int k = 0; k < 4; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 4);
                    tempimg[i][j].rgbtBlue = round(blue / 4);
                    tempimg[i][j].rgbtGreen = round(green / 4);
                }
                else if (i == height - 1)
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j + 1];
                    s[1] = image[i - 1][j + 1];
                    s[2] = image[i - 1][j];
                    s[3] = image[i][j];

                    for (int k = 0; k < 4; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 4);
                    tempimg[i][j].rgbtBlue = round(blue / 4);
                    tempimg[i][j].rgbtGreen = round(green / 4);
                }
                else
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j + 1];
                    s[1] = image[i + 1][j + 1];
                    s[2] = image[i + 1][j];
                    s[3] = image[i - 1][j];
                    s[4] = image[i - 1][j + 1];
                    s[5] = image[i][j];

                    for (int k = 0; k < 6; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 6);
                    tempimg[i][j].rgbtBlue = round(blue / 6);
                    tempimg[i][j].rgbtGreen = round(green / 6);
                }
            }
            else if (j == width - 1)
            {
                if (i == 0)
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j - 1];
                    s[1] = image[i + 1][j - 1];
                    s[2] = image[i + 1][j];
                    s[3] = image[i][j];

                    for (int k = 0; k < 4; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 4);
                    tempimg[i][j].rgbtBlue = round(blue / 4);
                    tempimg[i][j].rgbtGreen = round(green / 4);
                }
                else if (i == height - 1)
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j - 1];
                    s[1] = image[i - 1][j - 1];
                    s[2] = image[i - 1][j];
                    s[3] = image[i][j];

                    for (int k = 0; k < 4; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 4);
                    tempimg[i][j].rgbtBlue = round(blue / 4);
                    tempimg[i][j].rgbtGreen = round(green / 4);
                }
                else
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j - 1];
                    s[1] = image[i + 1][j - 1];
                    s[2] = image[i + 1][j];
                    s[3] = image[i - 1][j];
                    s[4] = image[i - 1][j - 1];
                    s[5] = image[i][j];

                    for (int k = 0; k < 6; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 6);
                    tempimg[i][j].rgbtBlue = round(blue / 6);
                    tempimg[i][j].rgbtGreen = round(green / 6);
                }
            }
            else
            {
                if (i == 0)
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j - 1];
                    s[1] = image[i + 1][j - 1];
                    s[2] = image[i + 1][j];
                    s[3] = image[i + 1][j + 1];
                    s[4] = image[i][j + 1];
                    s[5] = image[i][j];

                    for (int k = 0; k < 6; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 6);
                    tempimg[i][j].rgbtBlue = round(blue / 6);
                    tempimg[i][j].rgbtGreen = round(green / 6);
                }
                else if (i == height - 1)
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j - 1];
                    s[1] = image[i - 1][j - 1];
                    s[2] = image[i - 1][j];
                    s[3] = image[i - 1][j + 1];
                    s[4] = image[i][j + 1];
                    s[5] = image[i][j];

                    for (int k = 0; k < 6; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 6);
                    tempimg[i][j].rgbtBlue = round(blue / 6);
                    tempimg[i][j].rgbtGreen = round(green / 6);
                }
                else
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i - 1][j - 1];
                    s[1] = image[i - 1][j];
                    s[2] = image[i - 1][j + 1];
                    s[3] = image[i][j + 1];
                    s[4] = image[i + 1][j + 1];
                    s[5] = image[i + 1][j];
                    s[6] = image[i + 1][j - 1];
                    s[7] = image[i][j - 1];
                    s[8] = image[i][j];

                    for (int k = 0; k < 9; k++)
                    {
                        red += s[k].rgbtRed;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }

                    tempimg[i][j].rgbtRed = round(red / 9);
                    tempimg[i][j].rgbtBlue = round(blue / 9);
                    tempimg[i][j].rgbtGreen = round(green / 9);
                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimg[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimg[height][width];
    RGBTRIPLE s[9];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                if (i == 0)
                {
                    double red = 0;
                    double green = 0;
                    double blue = 0;

                    s[0] = image[i][j + 1];
                    s[1] = image[i + 1][j + 1];
                    s[2] = image[i + 1][j];

                    for (int k = 0; k < 3; k++)
                    {
                        red = (s[k].rgbtRed * 2) ^ 2 + (s[k].rgbtRed * 2) ^ 2;
                        green += s[k].rgbtGreen;
                        blue += s[k].rgbtBlue;
                    }
                }
                else if (i == height - 1)
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
                else if (i == height - 1)
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
                else if (i == height - 1)
                {
                }
                else
                {
                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimg[i][j];
        }
    }
    return;
}

int calGx(RGBTRIPLE pixel, int location)
{
    if (location == 11)
    {

    }
    else if (location = 12)
    {
    }
    else if (location = 13)
    {
    }
    else if (location = 14)
    {
    }
    else if (location = 15)
    {
    }
    else if (location = 16)
    {
    }
    else if (location = 17)
    {
    }
    else if (location = 18)
    {
    }
    else if (location = 19)
    {
    }
}
