#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
int main(int argc, string argv[])
{
    // substitution

    int kop = 0;
    bool ok = false;
    ok = false;
    int poi = 0;
    int gura[26];
    int khoi = 0;
    int lopa = 1;

    if (argc != 2)
    {
        printf("Usage: ./substitution key");

        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        return 1;
    }

    else if (strlen(argv[1]) == 26)
    {
        ok = true;
    }
    else if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.");
        ok = false;
    }


    else if ((int)argv[1][0] == 0)
    {
        while ((int)argv[1][kop] == 0)
        {
            kop++;
        }
        if ((int)argv[1][kop - 1] == 0)
        {
            printf("Usage: ./substitution key");
        }
        kop = 0;
    }

    else if ((int)argv[1][0] >= 65)
    {
        while (((int)argv[1][kop] >= 65 && (int)argv[1][kop] <= 90) || ((int)argv[1][kop] >= 97 && (int)argv[1][kop] <= 122))
        {
            kop++;
            ok = true;
        }
        if (((int)argv[1][kop - 1] >= 65 && (int)argv[1][kop - 1] <= 90) || ((int)argv[1][kop - 1] >= 97 && (int)argv[1][kop - 1] <= 122))
        {
            ok = false;
            printf("Usage: ./substitution key");
            return 1;
        }
    }

    else
    {
        printf("Usage: ./substitution key");
        ok = false;
    }

    // corrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
    if (ok == true)
    {

          int utopia = 1 ;
            while (poi < 26)
            {
                gura[poi] = argv[1][poi];
                poi++;
            }
            // koi is 0 lopa 1
            while (khoi < strlen(argv[1]))
            {
                while (lopa < strlen(argv[1]))
                {
                    if ((int)gura[khoi] == (int)gura[lopa] || (int)gura[khoi] == (int)gura[lopa] + 32 || (int)gura[khoi] + 32 == (int)gura[lopa])
                    {
                        ok = false;
                        return 1;
                    }
                    else
                    {
                        lopa++;
                    }
                }
                khoi++;
                utopia++;
                lopa= utopia;
            }



        int array[strlen(argv[1]) + 1];
        int parry[strlen(argv[1]) + 1];

        string k = get_string("plaintext : ");
        int p = 0;
        int haram = strlen(k);
        int pol = 97;
        int aol = 65;
        // copying chars into ints  of getint into array with -97
        while (p < haram)
        {
            if ((int)k[p] >= 65 && (int)k[p] <= 90)
            {

                while (aol != (int)k[p])
                {
                    aol++;
                }
                array[p] = aol;
                aol = 65;
                p++;
            }
            else if ((int)k[p] >= 97 && (int)k[p] <= 122)
            {
                while (pol != (int)k[p])
                {
                    pol++;
                }
                parry[p] = pol;
                pol = 97;
                p++;
            }
            else
            {
                p++;
            }
        }
        int ware = strlen(k);
        int reset = 0;
        // using ints of array w/ -97
        printf("ciphertext: ");
        while (reset < ware)
        {
            if ((int)array[reset] >= 65 && (int)array[reset] <= 90)
            {
                printf("%c", toupper(argv[1][array[reset] - 65]));
                reset++;
            }
            else if ((int)parry[reset] >= 97 && (int)parry[reset] <= 122)
            {
                printf("%c", tolower(argv[1][parry[reset] - 97]));
                reset++;
            }
            else
            {
                printf("%c", k[reset]);
                reset++;
            }
        }
        printf("\n");

    }
}
