#include <stdio.h>
void pos(int w, int x , int y , int z ) ; 
int main(void) {
	// your code goes here
	 int a  ; 
	 scanf("%i",&a);
	 for ( int i = 0 ;  i <a ;i++)
	 {
	     int w,x,y,z ; 
	     scanf("%i%i%i%i",&w,&x,&y,&z);
         pos(w,x,y,z);
	 }
	return 0;
}
void pos(int w, int x , int y , int z )  
{
     if( w==x||w==y||w==z)
     {
        printf("YES\n") ; 
    
     }
     else if (w==x+y+z)
     {
          printf("YES\n") ;
     }
     else if (w==x+y||w==x+z||w==z+y)
     {
          printf("YES\n") ;
     }
     else
     {
        printf("NO\n") ;
     }
}


