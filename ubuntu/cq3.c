#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
int ch(char c[],int max) ; 
int main()
{
    long a = 0 ; 
    scanf("%li",&a) ; 
    int as[a] ;
    for( int i = 0 ; i < a  ; i++)
    {
        char c[100] ;  
        scanf("%s",c) ; 
        int max = strlen(c)  ; 
        as[i] = ch(c,max) ; 
        
    }
    for ( int  j =  0 ; j < a ; j++)
    {
        printf("%i\n",as[j]) ; 
    }
}
int ch(char c[],int max)
{
    int d = 0 ; 
    for ( int i  = 0 ; i<max ; i++)
     {
        if(c[i] == '4' )
        {
            d++; 
        }
     }
     return d  ; 
     
}