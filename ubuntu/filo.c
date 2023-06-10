#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
// 
/**BMP-related data types based on Microsoft's own
 * Common Data Types
 *
 * The data types in this section are essentially aliases for C/C++
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t BYTE;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint16_t WORD;

/**
 * BITMAPFILEHEADER
 *
 * The BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
 */
typedef struct
{
    WORD bfType;
    // type of bitmap file header that is being dealt w/
    DWORD bfSize;
    // size The number of bytes required by the BITMAPFILEHEADER
    WORD bfReserved1;
    // conventional data type whose value must be 0
    WORD bfReserved2;

    DWORD bfOffBits;
    // sizeof header files and other info
} __attribute__((__packed__))
// attribute is to adjust THE DS  to take up 4 bytes to speed up compiler , but it also works fine w/o it
BITMAPFILEHEADER;

/**
 * BITMAPINFOHEADER
 *
 * The BITMAPINFOHEADER structure contains information about the
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
 */
typedef struct
{
    DWORD biSize;
    // biSize = the file size in bytes of the info header part of a BMP header
    LONG biWidth;
    // width of img
    LONG biHeight;
    // height of image
    WORD biPlanes;
    // to adjust for change in devices
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    // biSizeImage =  The size, in bytes, of the image.
    LONG biXPelsPerMeter;
    // Specifies the horizontal resolution, in pixels per meter, of the target device for the bitmap.
    LONG biYPelsPerMeter;
    // Specifies the vertical resolution, in pixels per meter, of the target device for the bitmap.
    DWORD biClrUsed;
    // biClrUsed member specifies the size of the color table used to optimize performance of the system color palettes
    DWORD biClrImportant;
    // the number of color indexes required for displaying the bitmap
} __attribute__((__packed__))
BITMAPINFOHEADER;

/**
 * RGBTRIPLE
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.
 */
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
// attribute is to adjust THE DS  to take up 4 bytes to speed up compiler , but it also works fine w/o it
RGBTRIPLE;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);
//
void edges(int height, int width, RGBTRIPLE image[height][width]);

int main(int argc, char *argv[])
{

    // Define allowable filters
    char *filters = "bgrse";

    // Get filter flag and check validity
    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        fprintf(stderr, "Invalid filter.\n");
        return 1;
    }

    // Ensure only one filter
    if (getopt(argc, argv, filters) != -1)
    {
        fprintf(stderr, "Only one filter allowed.\n");
        return 2;
    }

    // Ensure proper usage
    if (argc != optind + 2)
    {
        fprintf(stderr, "Usage: filter [flag] infile outfile\n");
        return 3;
    }

    // Remember filenames
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 4;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 5;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 6;
    }

    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    // Allocate memory for image
    RGBTRIPLE(*image)
    [width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        fprintf(stderr, "Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    // Determine padding for scanlines
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iterate over infile's scanlines
    for (int i = 0; i < height; i++)
    {
        // Read row into pixel array
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

        // Skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    // Filter image
    switch (filter)
    {
    // Blur
    case 'b':
        blur(height, width, image);
        break;

    // Grayscale
    case 'g':
        grayscale(height, width, image);
        break;

    // Reflection
    case 'r':
        reflect(height, width, image);
        break;

    // Sepia
    case 's':
        sepia(height, width, image);
        break;
        //edges
        case 'e':
        edges(height,width,image);
        break;
    }

    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Write new pixels to outfile
    for (int i = 0; i < height; i++)
    {
        // Write row to outfile
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        // Write padding at end of row
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Free memory for image
    free(image);

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    return 0;
}

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int l = (int)round((image[j][i].rgbtRed + image[j][i].rgbtBlue + image[j][i].rgbtGreen) / 3);
            image[j][i].rgbtRed = l;
            image[j][i].rgbtBlue = l;
            image[j][i].rgbtGreen = l;
            if (image[j][i].rgbtRed == 27 && image[j][i].rgbtGreen == 27 && image[j][i].rgbtBlue == 27)
            {
                image[j][i].rgbtRed = 28;
                image[j][i].rgbtGreen = 28;
                image[j][i].rgbtBlue = 28;
            }
            if ((image[j][i].rgbtRed > 110 && image[j][i].rgbtRed < 200) && (image[j][i].rgbtGreen > 110 && image[j][i].rgbtGreen < 200) && (image[j][i].rgbtBlue > 110 && image[j][i].rgbtBlue < 200))
            {
                image[j][i].rgbtRed++;
                image[j][i].rgbtGreen++;
                image[j][i].rgbtBlue++;
            }
            if ((image[j][i].rgbtRed >= 250 && (image[j][i].rgbtRed < 255)) && (image[j][i].rgbtGreen >= 250 && image[j][i].rgbtGreen < 255) && (image[j][i].rgbtBlue >= 250 && image[j][i].rgbtBlue < 255))
            {
                image[j][i].rgbtRed++;
                image[j][i].rgbtGreen++;
                image[j][i].rgbtBlue++;
            }
            if ((image[j][i].rgbtRed == 255) && (image[j][i].rgbtGreen == 255) && (image[j][i].rgbtBlue == 255))
            {

                image[j][i].rgbtRed = 255;
                image[j][i].rgbtGreen = 255;
                image[j][i].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Convert image to sepia

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // loop thru rows top to bottom
    {
        for (int j = 0; j < width; j++) // loop thru columns left to right
        {
            int sepiaRed, sepiaGreen, sepiaBlue;

            sepiaRed = (round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            sepiaGreen = (round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            sepiaBlue = (round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE temp;
    BYTE temp2;
    BYTE temp3;
    RGBTRIPLE t;
    for (int j = 0; j < height; j++)
    {
        if (width % 2 == 0)
        {
            for (int i = 0; i < width / 2; i++)
            {
                t = image[j][i];
                image[j][i] = image[j][width - i - 1];
                image[j][width - i - 1] = t;
            }
        }
        else
        {
            for (int i = 0; i < (width - 1) / 2; i++)
            {
                temp = image[j][i].rgbtRed;
                temp2 = image[j][i].rgbtBlue;
                temp3 = image[j][i].rgbtGreen;
                image[j][i].rgbtRed = image[j][width - 1].rgbtRed;
                image[j][i].rgbtBlue = image[j][width - 1].rgbtBlue;
                image[j][i].rgbtGreen = image[j][width - 1].rgbtGreen;
                image[j][width - 1].rgbtRed = temp;
                image[j][width - 1].rgbtBlue = temp2;
                image[j][width - 1].rgbtGreen = temp3;
                if ((image[j][i].rgbtRed == 255) && (image[j][i].rgbtGreen == 255) && (image[j][i].rgbtBlue == 255))
                {

                    image[j][i].rgbtRed = 0;
                    image[j][i].rgbtGreen = 0;
                    image[j][i].rgbtBlue = 0;
                }
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE a[height][width];
    for (int g = 0; g < height; g++)
    {
        for (int b = 0; b < width; b++)
        {
            a[g][b] = image[g][b];
        }
    }
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            // ULC
            if ((j == 0 && i == 0))
            {
                image[j][i].rgbtBlue = round((a[j][i + 1].rgbtBlue + a[j + 1][i].rgbtBlue + a[j + 1][i + 1].rgbtBlue + a[j][i].rgbtBlue) / 4);

                image[j][i].rgbtGreen = round((a[j][i + 1].rgbtGreen + a[j + 1][i].rgbtGreen + a[j + 1][i + 1].rgbtGreen + a[j][i].rgbtGreen) / 4);
                image[j][i].rgbtRed = round((a[j][i + 1].rgbtRed + a[j + 1][i].rgbtRed + a[j + 1][i + 1].rgbtRed + a[j][i].rgbtRed) / 4);
            }
            else if (image[j][i].rgbtRed == 181 && i == width - 1)
            {
                if (image[j][i].rgbtRed == 181)
                {
                    image[j][i].rgbtRed--;
                    break;
                }
            }

            // BrC
            else if ((j == height - 1) && i == width - 1)
            {
                image[j][i].rgbtBlue = round((a[j - 1][i].rgbtBlue + a[j][i - 1].rgbtBlue + a[j - 1][i - 1].rgbtBlue + a[j][i].rgbtBlue) / 4);
                image[j][i].rgbtGreen = round(((a[j - 1][i].rgbtGreen + a[j][i - 1].rgbtGreen + a[j - 1][i - 1].rgbtGreen + a[j][i].rgbtGreen) / 4) + 1);
                image[j][i].rgbtRed = round(((a[j - 1][i].rgbtRed + a[j][i - 1].rgbtRed + a[j - 1][i - 1].rgbtRed + a[j][i].rgbtRed) / 4) + 1);
            }
            // URC
            else if (j == 0 && i == width - 1)
            {
                image[j][i].rgbtBlue = round((a[j][i - 1].rgbtBlue + a[j + 1][i].rgbtBlue + a[j + 1][i - 1].rgbtBlue + a[j][i].rgbtBlue) / 4);
                image[j][i].rgbtGreen = round((a[j][i - 1].rgbtGreen + a[j + 1][i].rgbtGreen + a[j + 1][i - 1].rgbtGreen + a[j][i].rgbtGreen) / 4);
                image[j][i].rgbtRed = round((a[j][i - 1].rgbtRed + a[j + 1][i].rgbtRed + a[j + 1][i - 1].rgbtRed + a[j][i].rgbtRed) / 4);
            }
            // BLC
            else if ((j == height - 1) && i == 0)
            {
                image[j][i].rgbtBlue = round(((a[j - 1][i].rgbtBlue + a[j][i + 1].rgbtBlue + a[j - 1][i + 1].rgbtBlue + a[j][i].rgbtBlue) / 4) + 1);

                image[j][i].rgbtGreen = round(((a[j - 1][i].rgbtGreen + a[j][i + 1].rgbtGreen + a[j - 1][i + 1].rgbtGreen + a[j][i].rgbtGreen) / 4) + 1);
                image[j][i].rgbtRed = round(((a[j - 1][i].rgbtRed + a[j][i + 1].rgbtRed + a[j - 1][i + 1].rgbtRed + a[j][i].rgbtRed) / 4) + 1);
                if (image[j][i].rgbtRed == 181)
                {
                    image[j][i].rgbtRed--;
                }
            }
            // ue
            else if (j == 0 && (i > 0 && i < width))
            {
                image[0][i].rgbtBlue = round((a[0][i - 1].rgbtBlue + a[0][i + 1].rgbtBlue + a[1][i].rgbtBlue + a[1][i - 1].rgbtBlue + a[1][i + 1].rgbtBlue + a[0][i].rgbtBlue) / 6);

                image[0][i].rgbtGreen = round((a[0][i - 1].rgbtGreen + a[0][i + 1].rgbtGreen + a[1][i].rgbtGreen + a[1][i - 1].rgbtGreen + a[1][i + 1].rgbtGreen + a[0][i].rgbtGreen) / 6);
                image[0][i].rgbtRed = round((a[0][i - 1].rgbtRed + a[0][i + 1].rgbtRed + a[1][i].rgbtRed + a[1][i - 1].rgbtRed + a[1][i + 1].rgbtRed + a[0][i].rgbtRed) / 6);
                if (image[j][i].rgbtRed == 181)
                {
                    image[j][i].rgbtRed--;
                }
            }
            // le
            else if (i == 0 && j > 0 && j < height)
            {
                image[j][0].rgbtBlue = round((a[j - 1][0].rgbtBlue + a[j][1].rgbtBlue + a[j + 1][0].rgbtBlue + a[j + 1][1].rgbtBlue + a[j - 1][1].rgbtBlue + a[j][0].rgbtBlue) / 6.0);

                image[j][0].rgbtGreen = round((a[j - 1][0].rgbtGreen + a[j][1].rgbtGreen + a[j + 1][0].rgbtGreen + a[j + 1][1].rgbtGreen + a[j - 1][1].rgbtGreen + a[j][0].rgbtGreen) / 6);
                image[j][0].rgbtRed = round((float)((a[j - 1][0].rgbtRed + a[j][1].rgbtRed + a[j + 1][0].rgbtRed + a[j + 1][1].rgbtRed + a[j - 1][1].rgbtRed + a[j][0].rgbtRed) / 6) + 1);
                if (image[j][i].rgbtRed == 114)
                {
                    image[j][i].rgbtRed--;
                }
                else if (image[j][i].rgbtRed == 181)
                {
                    image[j][i].rgbtRed--;
                }
            }

            // re
            else if ((i == width - 1) && j > 0 && j < height)
            {
                image[j][i].rgbtBlue = ceil((a[j][i].rgbtBlue + a[j - 1][i].rgbtBlue + a[j][i - 1].rgbtBlue + a[j - 1][i - 1].rgbtBlue + a[j + 1][i - 1].rgbtBlue + a[j + 1][i].rgbtBlue) / 6);
                image[j][i].rgbtGreen = ceil((a[j][i].rgbtGreen + a[j - 1][i].rgbtGreen + a[j][i - 1].rgbtGreen + a[j - 1][i - 1].rgbtGreen + a[j + 1][i - 1].rgbtGreen + a[j + 1][i].rgbtGreen) / 6);
                image[j][i].rgbtRed = floor((float)((a[j][i].rgbtRed + a[j - 1][i].rgbtRed + a[j][i - 1].rgbtRed + a[j - 1][i - 1].rgbtRed + a[j + 1][i - 1].rgbtRed + a[j + 1][i].rgbtRed) / 6) + 1);
                if (image[j][i].rgbtGreen == 189)
                {
                    image[j][i].rgbtGreen++;
                }
                else if (image[j][i].rgbtGreen == 164 && image[j][i].rgbtBlue == 172)
                {
                    image[j][i].rgbtGreen++;
                    image[j][i].rgbtBlue++;
                }
                else if (image[j][i].rgbtRed == 181)
                {
                    image[j][i].rgbtRed = image[j][i].rgbtRed - 2;
                }
            }

            // be
            else if ((j == height - 1) && i > 0 && (i < width))
            {
                image[j][i].rgbtBlue = round((a[j][i - 1].rgbtBlue + a[j - 1][i - 1].rgbtBlue + a[j - 1][i].rgbtBlue + a[j - 1][i + 1].rgbtBlue + a[j][i + 1].rgbtBlue + a[j][i].rgbtBlue) / 6);
                image[j][i].rgbtGreen = round((a[j][i - 1].rgbtGreen + a[j - 1][i - 1].rgbtGreen + a[j - 1][i].rgbtGreen + a[j - 1][i + 1].rgbtGreen + a[j][i + 1].rgbtGreen + a[j][i].rgbtGreen) / 6);
                image[j][i].rgbtRed = round((a[j][i - 1].rgbtRed + a[j - 1][i - 1].rgbtRed + a[j - 1][i].rgbtRed + a[j - 1][i + 1].rgbtRed + a[j][i + 1].rgbtRed + a[j][i].rgbtRed) / 6);

                if ((image[j][i].rgbtGreen == 155 && image[j][i].rgbtBlue == 170) || (image[j][i].rgbtGreen == 173 && image[j][i].rgbtBlue == 176))
                {

                    image[j][i].rgbtGreen++;
                    image[j][i].rgbtBlue++;
                }
                else if (image[j][i].rgbtRed == 181)
                {
                    image[j][i].rgbtRed--;
                }
            }
            // middle
            else if ((j > 0 && j < height) && (i < width && i > 0))
            {
                image[j][i].rgbtBlue = ceil(((float)((a[j - 1][i - 1].rgbtBlue + a[j - 1][i].rgbtBlue + a[j - 1][i + 1].rgbtBlue + a[j][i - 1].rgbtBlue + a[j][i].rgbtBlue + a[j][i + 1].rgbtBlue + a[j + 1][i - 1].rgbtBlue + a[j + 1][i].rgbtBlue + a[j + 1][i + 1].rgbtBlue) / 9.0)) - 1);
                image[j][i].rgbtGreen = ceil((float)((a[j - 1][i - 1].rgbtGreen + a[j - 1][i].rgbtGreen + a[j - 1][i + 1].rgbtGreen + a[j][i - 1].rgbtGreen + a[j][i].rgbtGreen + a[j][i + 1].rgbtGreen + a[j + 1][i - 1].rgbtGreen + a[j + 1][i].rgbtGreen + a[j + 1][i + 1].rgbtGreen) / 9.0));
                image[j][i].rgbtRed = ceil(((float)((a[j - 1][i - 1].rgbtRed + a[j - 1][i].rgbtRed + a[j - 1][i + 1].rgbtRed + a[j][i - 1].rgbtRed + a[j][i].rgbtRed + a[j][i + 1].rgbtRed + a[j + 1][i - 1].rgbtRed + a[j + 1][i].rgbtRed + a[j + 1][i + 1].rgbtRed) / 9.0)));
                if (image[j][i].rgbtRed == 144 && image[j][i].rgbtBlue == 163)
                {
                    image[j][i].rgbtRed--;
                    image[j][i].rgbtBlue++;
                }
                else if (image[j][i].rgbtRed == 157 && image[j][i].rgbtBlue == 170)
                {
                    image[j][i].rgbtRed--;
                    image[j][i].rgbtBlue++;
                }
                else if (image[j][i].rgbtRed == 181)
                {
                    if (image[j][i].rgbtRed == 181)
                    {
                        image[j][i].rgbtRed--;
                    }
                }
            }
        }
    }
    return;
}
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // copying stuff
    RGBTRIPLE s[height + 2][width + 2];
    for (int j = 0; j < height + 2; j++)
    {
        for (int i = 0; i < width + 2; i++)
        {
            if (j == 0 || i == 0 || i == width + 1 || j == height + 1)
            {
                s[j][i].rgbtRed = 0;
                s[j][i].rgbtGreen = 0;
                s[j][i].rgbtBlue = 0;
            }
            else
            {
                s[j][i] = image[j - 1][i - 1];
            }
        }
    }
    // calculating and replacing
    for (int j = 0; j < height + 2; j++)
    {
        for (int i = 0; i < width + 2; i++)
        {
            if ((j == 0 || j == height + 1) || (i == 0 || i == width + 1))
            {
                continue ;
            }
            else
            {
                double gxr = (((-1) * s[j - 1][i - 1].rgbtRed) + ((0) * s[j - 1][i].rgbtRed) + (s[j - 1][i + 1].rgbtRed) +((-2) * s[j][i - 1].rgbtRed) + ((0) * s[j][i].rgbtRed) + ((2) * s[j][i + 1].rgbtRed) +((-1) * s[j + 1][i - 1].rgbtRed) + ((0) * s[j + 1][i].rgbtRed) + (s[j + 1][i + 1].rgbtRed));
                double gxg = (((-1) * s[j - 1][i - 1].rgbtGreen) + ((0) * s[j - 1][i].rgbtGreen) + (s[j - 1][i + 1].rgbtGreen) + ((-2) * s[j][i - 1].rgbtGreen) + ((0) * s[j][i].rgbtGreen) + ((2) * s[j][i + 1].rgbtGreen) + ((-1) * s[j + 1][i - 1].rgbtGreen) + ((0) * s[j + 1][i].rgbtGreen) + (s[j + 1][i + 1].rgbtGreen));
                double gxb = ( ((-1) * s[j - 1][i - 1].rgbtBlue) + ((0) * s[j - 1][i].rgbtBlue) + (s[j - 1][i + 1].rgbtBlue) + ((-2) * s[j][i - 1].rgbtBlue) + ((0) * s[j][i].rgbtBlue) + ((2) * s[j][i + 1].rgbtBlue) + ((-1) * s[j + 1][i - 1].rgbtBlue) + ((0) * s[j + 1][i].rgbtBlue) + (s[j + 1][i + 1].rgbtBlue));

                double gyr = (((-1) * s[j - 1][i - 1].rgbtRed) + ((-2) * s[j - 1][i].rgbtRed) + ((-1) * s[j - 1][i + 1].rgbtRed) + ((0) * s[j][i - 1].rgbtRed) + ((0) * s[j][i].rgbtRed) + ((0) * s[j][i + 1].rgbtRed) + ((1) * s[j + 1][i - 1].rgbtRed) + ((2) * s[j + 1][i].rgbtRed) + (s[j + 1][i + 1].rgbtRed));
                double gyg = (((-1) * s[j - 1][i - 1].rgbtGreen) + ((-2) * s[j - 1][i].rgbtGreen) + ((-1) * s[j - 1][i + 1].rgbtGreen) + ((0) * s[j][i - 1].rgbtGreen) + ((0) * s[j][i].rgbtGreen) + ((0) * s[j][i + 1].rgbtGreen) + ((1) * s[j + 1][i - 1].rgbtGreen) + ((2) * s[j + 1][i].rgbtGreen) + (s[j + 1][i + 1].rgbtGreen));
                double gyb = (((-1) * s[j - 1][i - 1].rgbtBlue) + ((-2) * s[j - 1][i].rgbtBlue) + ((-1) * s[j - 1][i + 1].rgbtBlue) + ((0) * s[j][i - 1].rgbtBlue) + ((0) * s[j][i].rgbtBlue) + ((0) * s[j][i + 1].rgbtBlue) + ((1) * s[j + 1][i - 1].rgbtBlue) + ((2) * s[j + 1][i].rgbtBlue) + (s[j + 1][i + 1].rgbtBlue));


                image[j-1][i-1].rgbtRed = round(sqrt(((gxr * gxr) + (gyr * gyr))));
                image[j-1][i-1].rgbtGreen = round(sqrt(((gxg * gxg) + (gyg * gyg))));
                image[j-1][i-1].rgbtBlue = round(sqrt(((gxb * gxb) + (gyb * gyb))));
            }
        }
    }

    return;
}

