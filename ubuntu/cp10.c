#include <stdio.h>
#include <math.h>
int ar[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void check(long z);
int main(void)
{
    // your code goes here
    int a;
    scanf("%i", &a);
    long z;
    for (int i = 0; i < a; i++)
    {
        long  b, c;
        scanf("%lu%lu",&b,&c);

        z = b + c;
        check(z);
    }
    return 0;
}
void check(long z)
{
    long pr = 0;
    long x;
    if (z==0)
    {
        printf("%i",ar[0])  ; 
        return  ; 
    }
    for (long i = 0; z / pow(10, i) >= 1; i++)
    {
        x = i;
    }
    x++ ; 
   for ( long j  = 0 ;  j <x ; j++)
   {
       long xo = (z/(long)pow(10,j))%10 ; 
       pr+=ar[xo] ; 
   }
    printf("%li", pr);
}
