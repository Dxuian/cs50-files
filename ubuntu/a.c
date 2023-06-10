#include<time.h>
#include <stdio.h>
#include <string.h>

int main(void)
{  
   printf("%li , %li",clock(), (time(NULL)/31536000)); 
   long j = time(NULL); 
   while(1)
   {
      if(j==time(NULL))
      {
         continue ; 
      }
      printf("%li\n",j) 
      ; j=time(NULL) ;
   }
  
   
    
}  