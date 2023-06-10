#include <stdio.h>
void check( int b , int c , int ar[]) ;
int main(void) {
	// your code goes here
	int a ; 
	scanf("%i",&a) ; 
	for ( int i = 0 ; i< a ;i++)
	{
	  int b ,c ; 
	  scanf("%i%i",&b,&c) ; 
	  int ar[b]  ;
	  for ( int j = 0 ;  j<b ;j++)
	  {
	      scanf("%i",&ar[j]) ; 
	  }
	  check(b,c,ar);
	}
	return 0;
}
void check( int b , int c , int ar[]) 
{
    int no = 0 ; 
    for ( int i = 0 ; i < b ; i++)
    {
        if(ar[i]<c)
        {
             
        }
        else if(ar[i]>=c)
        {
           no++ ;  
        }
    }
    printf("%i\n",no) ; 
}

