#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    long a = get_long("enter your card number:");
    int x = 1  ;
    int z ;
    int y = 0 ;
    int s = 0  ;
    int d,k,m,g,h;
     long c ;
    int f = 1;
    int p = 0;
    bool checksum ;
    long l,n,j,w,i,q ;
    n = a/ pow(10,12);
    j = a/ pow(10,14);
    i = a/pow(10,15);
    q = a/ pow(10,13);


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
            d = (k%10)+1 ;
        }

       y +=d ;
        x+=2;
    }
    x=p ;
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
         checksum = 1;


     }
     else
     {
         checksum = 0 ;
         printf("INVALID\n");
     }

     if (checksum==1)
     {
         if (n%10==4||i%10==4)
         {
             w=1;

         }

         else if( j % 100 == 52 || j % 100 == 53 || j % 100 == 51||j % 100==54||j % 100==55)
         {
            w=2;

         }
         else if (q%100==34||q%100==37)
         {
             w=3;

         }
         else
         {
             w=4;

         }
         switch (w)
         {
             case 1:
             printf("VISA\n");
             break ;
             case 2 :
             printf("MASTERCARD\n");
             break ;
             case 3 :
             printf("AMEX\n");
             break ;
             case 4 :
             printf("INVALID\n");
             break;
             default:
             printf("INVALID\n");
             break;

         }
         checksum=0;
     }
}
//sort2 merge
//sort 1 
//sort 3 