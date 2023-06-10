// BMP-related data types based on Microsoft's own

#include <stdint.h>

/**
 * Common Data Types
 *
 * The data types in this section are essentially aliases for C/C++
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
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
    WORD   bfType;
    //type of bitmap file header that is being dealt w/
    DWORD  bfSize;
    //size The number of bytes required by the BITMAPFILEHEADER
    WORD   bfReserved1;
    // conventional data type whose value must be 0 
    WORD   bfReserved2;

    DWORD  bfOffBits;
    //sizeof header files and other info 
} __attribute__((__packed__))
//attribute is to adjust THE DS  to take up 4 bytes to speed up compiler , but it also works fine w/o it 
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
    DWORD  biSize;
    //biSize = the file size in bytes of the info header part of a BMP header
    LONG   biWidth;
    //width of img 
    LONG   biHeight;
    //height of image 
    WORD   biPlanes;
    //to adjust for change in devices 
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    //biSizeImage =  The size, in bytes, of the image.
    LONG   biXPelsPerMeter;
    //Specifies the horizontal resolution, in pixels per meter, of the target device for the bitmap.
    LONG   biYPelsPerMeter;
    //Specifies the vertical resolution, in pixels per meter, of the target device for the bitmap.
    DWORD  biClrUsed;
    // biClrUsed member specifies the size of the color table used to optimize performance of the system color palettes
    DWORD  biClrImportant;
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
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
//attribute is to adjust THE DS  to take up 4 bytes to speed up compiler , but it also works fine w/o it 
RGBTRIPLE;
