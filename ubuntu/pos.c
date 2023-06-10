#include <stdio.h>
#include <stdlib.h>
#include<cs50.h>
#include <math.h>
void so(int a[], int l, int r, int fdd);
void me(int a[], int l, int m, int r,int fdd);
int main()
{
    // int ad = get_int("enter no of entries");
    int a[] = {124,42,35,65,57,75,86,976,98,79,57,4,3,1,43,46,76,87,2534,3756,4673,557,64574} ;
    int fdd= sizeof(a)/sizeof(a[0]) ; 
    // for(int t=0 ;t < ad ;t++)
    // {
    //     a[t] = get_int("enter the number  :   ")  ; 
    // }
    so(a, 0, sizeof(a)/sizeof(a[0]),fdd);
    for (int i = 1; i <= sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%i\t", a[i]);
    }
}
void so(int a[], int l, int r,int fdd)
{
    int mid = (l + r-2 )/2;
    if (l < r)
    {
        so(a, l, (l + r) / 2,fdd);
        so(a, ((l + r) / 2) + 1, r,fdd);
        me(a, l, ((l + r) / 2), r,fdd);
    }
}
void me(int a[], int l, int m, int r,int fdd)
{
    int q = 0, w = 0, e = 0, ar[m - l + 1], aw[r - m];
    int left = l, right = r ;
    

    // correct
    for (int i = l; i <= m; i++)
    {
        ar[i - l] = a[i];
    }
    for (int j = m + 1; j <= r; j++)
    {
        aw[j - (m + 1)] = a[j];
    }

    int len1 = m + 1 - l;
    int len2 = r - m;
    int f[len1 + len2];

    while (((sizeof(ar) / sizeof(ar[0])) - q > 0) && ((sizeof(aw) / sizeof(aw[0])) - w > 0))
    {
        if (ar[q] > aw[w])
        {
            f[e] = aw[w];
            e++;
            w++;
        }
        else if (ar[q] <= aw[w])
        {
            f[e] = ar[q];
            q++;
            e++;
        }
    }
    // aw , q for left ar,w for rite
    if (len1 - q > 0)
    {
        while (q <= (sizeof(f) / sizeof(f[0])) - 1 && len1 - q > 0)
        {
            f[e] = ar[q];
            e++;
            q++;
        }
    }
    if (len2 - w > 0)
    {
        while (w <= (sizeof(f) / sizeof(f[0])) - 1 && len2 - w > 0)
        {
            f[e] = aw[w];
            e++;
            w++;
        }
    }
    for (int i = left; i-left <= (sizeof(f)/sizeof(f[0]))-1; i++)
    {
        a[i] = f[i - left];
    }
     for (int i = 1; i <= fdd; i++)
    {
        printf("%i\t", a[i]);
    }

   
    printf("\n");
}