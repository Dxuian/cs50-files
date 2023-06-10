#include <stdio.h>

int main(void) {
	// your code goes here
	int a ; 
	scanf("%i",&a);
	for( int i =  0 ; i< a ; i++)
	{
	    int b ; 
	    scanf("%i",&b);
	    char c[b] ; 
	    scanf("%s",c);
	    int o = 0,z = 0 ;
	    for( int j  = 0 ; j < b ; j++)
	    {
	        if(          (c[j])=='1'       ) 
	        {
	            o++;
	        }
	        else
	        {
	            z++;
	        }
	        
	    }
	    if(o%2!=0||z%2!=0)
	    {
	        printf("NO\n");
	    }
	    else
	    {
	        printf("YES\n");
	    }
	}
	return 0;
}

