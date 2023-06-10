#include <stdio.h>
#include <cs50.h>
int main(void)
{
  cint array[8] = {1,2,2,2,5,5,6,6,};
    int polo = 0 ;
    int koala = 1;
    int carry[9];
    int candidate_count = 8 ;
    while (polo<candidate_count)
    {
        while (koala < candidate_count)
        {
            if(array[polo]==array[koala])
            {
                carry[polo]++;
                koala++;
            }
            else
            {
                koala++;
            }
        }
        polo++;
        koala = polo + 1 ;
    }

}


