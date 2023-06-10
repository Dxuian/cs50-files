#include <stdio.h>

int main(void) {
	// your code goes here
	int a ; 
	scanf("%i",&a) ; 
	for ( int  i = 0 ; i < a ;i++)
	{
	    int b,c,d  ; 
	    scanf("%i%i%i",&b,&c,&d) ; 
	    if(b+c==d||c+d==b||d+b==c)
	    {
	       printf("yes\n") ; 
	    }
	    else
	    {
	        printf("no\n") ; 
	    }
	}
	return 0;
}

