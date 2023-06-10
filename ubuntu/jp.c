#include <stdio.h>

int main(void) {
	// your code goes here
	 int  a; 
	 scanf("%i",&a) ; 
	 for( int i  = 0  ; i < a ; i++)
	 {
	     int b,c ;
	     scanf("%i%i",&b,&c) ; 
	     int ar[b];
for ( int is = 0 ; is < b ; is++)
         {
             scanf("%i",&ar[is]); 
         }
         for ( int j = 0 ; j < b ;j++)
         {
             if(ar[j]<=c)
             {
                 printf("1");
                 c-=ar[j] ; 
             }
             else 
             {
                 printf("0") ; 
                 continue  ; 
             }
         }
         printf("\n");
	 }
	return 0;
}

