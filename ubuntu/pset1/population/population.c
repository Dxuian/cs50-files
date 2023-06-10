#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int a = get_int("enter the starting population:");
    while (a < 9)
    {
       a = get_int("enter the number again because it was lesser than 9 and acc to math population stagnates if the nunmebr is 9 :");
    }
    int s =a ;
    // TODO: Prompt for end size
    int b =  get_int("enter the final  population:");
    while (b<a)
    {
       b = get_int("enter the number again because final population cannt be lesser than the inital one :"); 
    }
    // TODO: Calculate number of years until we reach threshold
    int x =0;
    do 
    {
        
        s= s+ (s/3)-(s/4);
        x++;
    }
    while (s<b);
    // TODO: Print number of years
    printf("Years: %i", x);
   
}