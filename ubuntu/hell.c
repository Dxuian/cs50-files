#include <stdio.h>
#include <strings.h>
#include <string.h>
void check( int in[], char ou[], int b );
int main(void) {
	// your code goes here
int a ;
scanf("%i",&a);
for ( int i=0; i<a ;i++)
{
    int b ;
    scanf("%i",&b);
    int in[b] ; 
    char ou[b];
    for ( int j =0; j < b ;j++)
    {
        scanf("%i",&in[j]);
    }
    scanf("%s",ou);
    check(in,ou,b);
}
	return 0;
}
void check(int in[] , char ou[] ,int b )
{
    int min  = 0 ; 
    for (int i =0 ; i < b ; i++)
    {
        if((char)ou[i]=='0' && in[i] < min && min!=0)
        {
          min  = in[i]; 
        }
        
        else if ( (min==0) && ((char)ou[i] == '0') ) 
        {
            min = in[i] ; 
        }
        
    }
    printf("%i\n",min);
}