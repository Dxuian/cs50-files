#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
     int a= get_int("enter the strating population size : ");
     
    // TODO: Prompt for end size
     int b= get_int("enter the end population size \n ");
    // TODO: Calculate number of years until we reach threshold
    int x = 0;
    while  (a<b,x++)
      {
         a = (a + (a/3) -(a/4)) ;
          // TODO: Print number of years
    
      }
    printf("the number of years is : %i" , x);
}


   

    