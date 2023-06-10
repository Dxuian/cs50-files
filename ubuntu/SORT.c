#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
   int array[4] = {4,3,1,2};
   int parry[4] = {4,3,1,2};
   int p = 0 ;
   int po = 1 ;
   int candidate_count = 4;
   
    while(p< candidate_count )
    {
        while ( po <  candidate_count   )
        {
            if(array[p] > array [po])
            {
                 array[p] = parry[po];
                 array[po]= parry[p];
                 parry[p]=array[p];
                 parry[po]= array[po];
                po++;
            }
            else if (array[p]==array[po])
            {
                po++;
            }
            else
            {
                po++;
            }
        }
        p++ ;
        po = p + 1 ;
    }
    for ( int d = 0 ; d<4 ; d++)
    {
        printf("%i",array[d]);
    }
}