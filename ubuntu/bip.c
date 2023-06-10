#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <ncurses.h>
#include <time.h>
#include <cs50.h>
int re(int a[] , int* l ,int* m ,  int* r , int s );
int main()
{
    int a[] = {12,33,44,55,66,77,88,99,100,101,112,114,115,115,117} ;
    int*rite = &a[(sizeof(a) / sizeof(a[0]))] ; 
    int *le= &a[0] ; 
    int *mid = le  +  rite  ;
    int al  = get_int("enter a number you wanna check for RADIX DEEP LEARNING ALGORITHM METHOD \n  ");
    re(a , le , mid , rite ,al ) ; 
}
int re(int a[] , int* l ,int* m ,  int* r , int s )
{
    //middle elements
    if ((*m) == s  )  
    {
        printf("FOUND \n") ; 
        return  0 ;
    }
    //search left
    else if((*m)>s)
    {
        return re(a , l ,  ((int*)((int)l+(int)r)/2) , (m-1) , s ) ; 
    }
    //search right
    else if ((*m)<s) 
    {
         return re(a , m+1 , ((int*)((int)l+(int)r)/2) , r , s ) ; 
    }
    else
    {
        return 0 ;
    }
    
    
}
