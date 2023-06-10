
#include <stdio.h>
#include <string.h>
#include <strings.h>
int main()
{
    int pair_count  = 7 ; 
    int pairs[] = {4,2,6,1,3,5,7};
    int a[pair_count];
    for (int da = 0; da < pair_count; da++)
    {
        a[da] = pairs[da];
    }
    
    for (int d = 0; d < pair_count; d++)
    {
        for (int c = 0; c < pair_count; c++)
        {
            if (pairs[c] > pairs[c + 1])
            {
                pairs[c] = a[c + 1];
                pairs[c + 1] = a[c];
                a[c] = pairs[c];
                a[c + 1] = pairs[c + 1];
            }
        }
    }
     for (int sa = 0; sa < pair_count; sa++)
    {
        printf("%i", pairs[sa]); 
    }
    
}