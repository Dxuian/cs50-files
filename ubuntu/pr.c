#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<strings.h>
#include<cs50.h>
#include<ncurses.h>
int re(int a ) ; 
int main()
{
    int a = get_int("enter a number to check if its prime")  ;
    printf("%i",re(a)) ; 
}
int re(int a ) 
{
    x
    if(a%x!=0)
    {
        x++ ; 
        return re(a) ; 
    }
    else if(a%x==0&& a==x)
    {
        printf("doesnt exist") ; 
        exit(0) ; 
    }
    else if(a%x==0&& a!=x)
    {
       return 1 ;
    }
    else 
    {
        return 0 ; 
    }
    
}