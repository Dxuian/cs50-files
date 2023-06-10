#include <stdio.h>
void pro(int li[], float n, int a, int b);
int main(void)
{
    // your code goes here
    int t;
    scanf("%i", &t);
    for (int i = 0; i < t; i++)
    {
        float n ;
        int a, b;
        scanf("%f%i%i", &n, &a, &b);
        int li[(int)n];
        for (int it = 0; it < n; it++)
        {
            scanf("%i", &li[it]);
        }
        pro(li, n, a, b);
    }
    return 0;
}
void pro(int li[], float n, int a, int b)
{
    float ap = 0 ,bp = 0;
    for (int i = 0; i < n; i++)
    {
        if (li[i] == a)
        {
            ap++;
        }
    }
    for ( int x = 0 ; x<n ;x++)
    {
        if(li[x]==b)
        {
            bp++ ; 
        }
    }
    printf("%f\n", ((ap * bp) / (n * n))) ; 
}
