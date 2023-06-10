#include <cs50.h>
#include <stdio.h>

int main()
{
    string array[5][5];
    bool cool = false ;
    int x = 0 ;
    while (x<5)
   {
       string a = get_string("enter: ");
       if ( (int)a>=65 && (int)a<=90)
       {
           array[x][cool] = a ; 
           x++;
       }
       else 
       {
            cool= true ;
           array[x][cool]= a ;
           x++;
       }
       cool = false ;
       
      
       
   }
    int ab = get_int("enter: ");
       int bc = get_int("enter ");
       printf("%s ",array[ab][bc]);
}