#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <strings.h>
int rer(string a , int x ) ; 
int main()
{
   string a =  get_string("enter the string you wanna reverse")   ;
    int x =strlen(a);
    printf("%i\n",x )  ; 
   rer(a,x) ; 
}


int rer(string a , int x )
{
 if ( x>=1)
{
     printf("%c",a[x-1]) ; 
     return rer(a , x-1) ; 
 }
 else {
     return 0  ; 
 }
}
