#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>
int re(int a[], int s);
int main()
{
    int a[] = {5, 3, 2, 1, 6, 4};
    int as = sizeof(a) / sizeof(a[0]);
    re(a, as);
}

int re(int a[], int s)
{
    if (s == 2)
    {
        if (a[0] > a[1])
        {
            int temp = 0;
            a[0] = temp;
            a[0] = a[1];
            a[1] = temp;
        }
        return 0 ;
    }
    else
    {
        if(s==1)
        {
            return 
        }
        if (s % 2 == 0)
        {
            int cap[s / 2];
            int cap2[s / 2];

            for (int i = 0; i < s / 2; i++)
            {
                cap[i] = a[i];
                cap2[i ] = a[i+(s/2)];
            }
        int po = (sizeof(cap) / sizeof(cap[0]));
        int pop = (sizeof(cap2) / sizeof(cap2[0]));
        return re(cap, po);
        return re(cap2, pop);
        }
        else
        {
            int cap[(s + 1) / 2];
            int cap2[(s - 1) / 2];
            for (int i = 0; i < (s +1)/ 2; i++)
            {
                cap[i] = a[i];
    
            }
            for( int k =  0 ; k < (s-1)/2 ; k++ )
            {
                cap2[k] = a[k+((s+1)/2)]  ; 
            }
        int po = (sizeof(cap) / sizeof(cap[0]));
        int pop = (sizeof(cap2) / sizeof(cap2[0]));
        return re(cap, po);
        return re(cap2, pop);
        }


    }
}