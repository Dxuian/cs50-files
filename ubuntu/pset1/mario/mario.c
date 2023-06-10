#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int h = get_int("Height:");
    if (h < 1)
    {
        h = get_int("Height:");
    }
    int y = 1 ;
    int blank = 1;
    int blankr = 1;
    int hashr = 0 ;
    int hash = 0;
    //loop begins 
    while (y <= h)
    {
        //making blank spaces
        while (blank - 1 < h - y)
        {
            printf(" ");
            blank++;
        }
        //making hashes 
        while (hash <= h - blank)
        {
            printf("#");
            hash++;
        }
        hash = hashr;
        printf("  ");
        //making blank spaces after resetting value of hash 
        while (hash <= h - blank)
        {
            printf("#");
            hash++;
        }
        printf("\n");
        //prepping to restart the loop
    
        hash = hashr; 
        blank = blankr;
        y++;
    }
}    