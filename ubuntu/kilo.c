#include <stdio.h>

int main(void) {
	// your code goes here
	int a  ;  
	scanf("%i",&a) ; 
	for( int i = 0 ; i< a ; i++)
	{
	    int b,c,d,e  ;
	    scanf("%i%i%i%i",&b,&c,&d,&e) ; 
	    if (b==d || c==e)
	    {
	        printf("YES\n") ; 
	    }
	    else 
	    {
	        printf("NO\n") ; 
	    }
	}
	return 0;
}

