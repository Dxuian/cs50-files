#include <stdio.h>
#include <math.h>
int main()
{
    printf("enter the number of digits in the array");
    int ds;
    scanf("%i", &ds);

    int a[100], b[100];
    // b ko zero kr rha hu
    for (int i = 0; i < 100; i++)
    {
        if (i < ds)
        {
            b[i] = 1;
        }
        else
        {
            b[i] = 0;
        }
    }
    // taking values
    for (int i = 0; i < ds; i++)
    {
        printf("enter the %i th number \n", i+1);
        scanf("%i", &a[i]);
    }
    // setting frequencies
    for (int i = 0; i < ds; i++)
    {
        for (int j = i + 1; j < ds; j++)
        {
            if (a[i] == a[j])
            {
                b[i]++;
            }
        }
    }
    int co = 0 ;
    // deleting elements
    for (int p = 0; p <= ds; p++)
    {
        if (b[p] >= 2)
        {
            co++ ;
            for (int k = p + 1; k <= ds; k++)
            {
                if (a[k] == a[p])
                {
                    // elemet detected deleting now
                    //  a[k]= a[k+1] ;
                    for (int d = k; d <= ds; d++)
                    {
                        a[d] = a[d + 1];
                    }
                }
            }
        }
    }
    //print cuz output showing 
    for(int f = 0 ; f<ds-co ;f++)
    {
        printf("%i\t",a[f]);
    }
}