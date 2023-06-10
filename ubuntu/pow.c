#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<strings.h>
#include<cs50.h>
#include<ncurses.h>
int re(int a , int b);
int main()
{
    int a =3 ;
    int b =3;
    printf("%i",re(a,b)) ;
}
int re(int a , int b )
{
   if(b==1)
   {
       return a  ;
   }
   else
   {
       return a*re(a,b-1) ;
   }
}