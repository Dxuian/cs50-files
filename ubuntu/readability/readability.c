#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
    string a = get_string("Enter:  ");
    int x = 0;
    int word = 1;
    int sentence = 0;
    int letter = 0;
    int i = strlen(a);
    while (x <= i)
    {
        // useless chars
        if ((int)a[x] < 32)
        {
            x++;
        }
        // space
        else if ((int)a[x] == 32)
        {
            x++;
            word++;
        }
        // fixing stuff

        //!
        else if (((int)a[x] == 33) && ((int)a[x - 1] == 32))
        {
            sentence++;
            x++;
        }
        else if (((int)a[x] == 33) && ((int)a[x - 1] != 32))
        {
            sentence++;
            word++;
            x++;
        }
        // useless chars
        else if ((int)a[x] > 33 && (int)a[x] < 46)
        {
            x++;
        }
        // full stop
        else if ((int)a[x] == 46 && (int)a[x - 1] == 32)
        {
            sentence++;
            x++;
        }
        else if ((int)a[x] == 46 && (int)a[x - 1] != 32)
        {
            sentence++;
            x++;
        }
        // useless chars
        else if (((int)a[x] > 46 && (int)a[x] < 63) || ((int)a[x] > 63 && (int)a[x] < 65))
        {
            x++;
        }
        //?
        else if ((int)a[x] == 63 && (int)a[x - 1] == 32)
        {
            sentence++;
            x++;
        }
        else if ((int)a[x] == 63 && (int)a[x - 1] != 32)
        {
            sentence++;
            word++;
            x++;
        }
        // letters
        else if (((int)a[x] >= 65 && (int)a[x] <= 90) || ((int)a[x] >= 97 && (int)a[x] <= 122))
        {
            letter++;
            x++;
        }
        else
        {
            x++;
        }
    }
    float L = (100 * letter) / word;
    float S = (100 * sentence) / word;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int pole = (int)round(index);
    if (pole < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (pole >= 1 && pole <= 16)
    {
        printf("Grade %i\n", pole);
    }
    else if (pole > 16)
    {
        printf("Grade 16+\n");
    }
    return 0;
}