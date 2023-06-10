#include<stdio.h>
int main()
{
    int a[] = {1,5} ; 
    int b[] ={3} ; 
    int c[3] ; 
    int e=0 , q= 0 ,w= 0 ; 
    while (2-q>0 && 1-w>0)
    {
        if(a[q]  < b[w] && 2-q >0  )
        {
            c[e] = a[q] ; 
            e++ ;q++;
        }
        else if (a[q] >= b[w] && 2-w> 0 )
        {
            c[e] = b[w] ; 
            e++;w++ ; 
        }
    }
}