#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    long a = get_long ("enter your card number:") ;
    int x = 1  ;
    int z ;
    int y = 0 ;
    int s = 0  ;
    int d,k,m,g,h;
     long c ;
    int f = 1;
    int p = 0;
    bool checksum ;
    long l,n,j,w,i ;
    n = a/ pow(10,13);
    j = a/ pow(10,15);
    i = a/pow(10,16);
    while ((a / pow(10, x) )> 1)
    {

        c = (a/pow(10 ,x)) ;
        z= c % 10 ;
        k = 2*z ;
        if  (k<10)
        {
            d = k;
        }
        else if (k>10||k==10)
        {
            d = (k%10) ;
        }

        y +=d;
        x+=2;
    }
    x=p;

    while ( (a / pow(10,x) )>1 )
    {
        l= a/(pow(10, x));
        m = l % 10 ;
        s += m;
        x+=2;
    }
     g= s+y;
     if(g%10==0)
     {
         checksum = 1 ;

     }
     else
     {
         checksum = 0 ;
         printf("INVALID\n");
     }