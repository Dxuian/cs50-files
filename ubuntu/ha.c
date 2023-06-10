#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<strings.h>
#include<cs50.h>
#include<ncurses.h>
int re(int  a) ; 

int main()
{
    int a = 13 ;
    re(a) ; 
}
int re(int a )
{
    if(a==1)
    {
        printf("1") ; 
        return 0 ;
    }
    else if(a%2==0)
    {
        printf("%i  ",a) ;
        return re(a/2) ; 
    }
    else if(a%2==1)
    {
         printf("%i  ",a) ;
         return re(      ((3*a)+1)    ) ;
    }
    else 
    {
        return 0 ;
    }
}