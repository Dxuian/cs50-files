#include <stdio.h>
#include <cs50.h>
int collatz ( int n );
int  main (void)
{
    
    int a = 50 ;
    int collat = collatz(a);
    printf("the number of steps is %i",collat);
    
}
int  collatz ( int n  )
{ 
    int x = 0 ;
     
    if (n==1)
    {
     
        return x ;
    }
    else if (n%2==0)
    {
       return 1 +  collatz(n/2);
    }
    else
    {
         return 1 +  collatz( (3* n) + 1 );
    }
    return x ; 
    
}
