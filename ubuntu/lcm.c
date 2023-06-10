#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<strings.h>
#include<cs50.h>
#include<ncurses.h>
int re(int a , int b) ; 
int main()
{
    int a = get_int("enter your number ") ; 
    int b = get_int("enter your number ") ; 
    printf("%i",re(a,b)) ; 
    
}
int re(int a , int b )
{
    static int x = 2   ; 
    static int xb = 1   ; 
    
    if(a==1||b==1 || a==x ||b==x) 
    {
        // return x  ;
        return a*b;
    }
    else if(a!=1&&b!=1)
    {
        if(a%x==0 && b%x==0)
        {
            xb*=x;
            x++ ; 
            
         return xb ;    
        }
        else if (a%x==0 && b%x!=0)
        {
             xb*=x;
              x++ ; 
            return re(a/x , b) ; 
        }
        else if (a%x!=0 && b%x==0)
        {
            xb*=x;
            x++ ; 
            return re(a , b/x) ; 
        }
        else if (a%x!=0 && b%x!=0)
        {
           
            x++ ; 
            return re(a , b);
        }  
         else 
        {
            return 0 ;
        }
        
    }
     else 
        {
            return 0 ;
        }
   
    
}