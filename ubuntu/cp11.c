#include <stdio.h>
void check(int n , int ar[], int ar1[]);
int main(void)
{
    // your code goes here
    int a;
    scanf("%i", &a);

    for (int i = 0; i < a; i++)
    {
        int n ;
        scanf("%i",&n);
        int ar[n] ;
        int ar1[n] ;
        
        for ( int is  = 0 ; is < n ; is++)
    {
        scanf("%i",&ar[is]) ;
    }
    for ( int is  = 0 ; is < n ; is++)
    {
        scanf("%i",&ar1[is]) ;
    }

        check(n,ar,ar1);
    }
    return 0;
}
void check(int n , int ar[], int ar1[])
{
    int max = 0 ,max1 = 0  ;
    for ( int i = 0 ; i < n ; i++)
    {

        if (ar[i] > max  )
        {
            max  =  ar[i] ;
        }

        if (ar1[i] > max1  )
        {
            max1  =  ar1[i] ;
        }

    }
    int sum = 0 , sum1 = 0 ;
    for ( int j  =0  ; j<n ;j++)
    {
        if(ar[j] == max)
        {
            continue ;
        }
        else
        {
            sum+= ar[j] ;
        }

    }
    for ( int j = 0; j < n ;j++)
    {
         if(ar1[j] == max1)
        {
            continue ;
        }
        else
        {
            sum1+= ar1[j] ;
        }
    }

    if(sum>sum1)
    {
        printf("Alice\n");
        return ; 
    }
    else if(sum<sum1)
    {
        printf("Bob\n");
        return ; 
    }
    else if (sum==sum1)
    {
        printf("Draw\n") ;
        return ; 
    }


}
