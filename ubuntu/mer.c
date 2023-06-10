#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<strings.h>
#include<string.h>
#include<time.h>
int *me(int a[] ,  int b[]  ,  int al , int bl ) ; 
int* two(int* a,int l , int r) ;
int *so(int a[] ,  int l, int r) ; 
int main()
{
    int a[] = {3,4,6,2,5,1} ; 
    
    int *fi =  so(a, 0, 6) ; 
    for ( int i  = 0 ; i <6  ; i++)
    {
        printf("%i",*(fi+i)) ; 
    }
    
}
int* so(int a[] ,  int l, int r)
{
    int mid  = (l+r)/2 ;
    if(l<r && l<mid )
    {
     int *left = so(a , l , mid-1) ;
     int *rite = so(a , mid, r) ;
     int* final = me( left , rite , l , r )  ; 
     return final  ; 
    }
   
    else if(l==r)
    {
        return &a[l] ; 
    }
    else 
    {
        return  two(a,l-1,r-1)  ;
    }
   
}
int* two(int* a,int l , int r)
{
    int temp = 0  ;
    if(a[l]>a[r])
    {
        a[l] = temp ; 
        a[l] = a[r] ; 
        a[r] = temp ; 
        return a ; 
        
    }
    else 
    {
        return a   ; 
    }
}
int* me(int a[] ,  int b[]  ,  int al , int bl )
{
    if(b==NULL)
    {
        return a ;
    }
    else if( a==NULL)
    {
        return b  ; 
    }
    else 
    {
       int q=0 ,w =0 , e = 0 ; 
       int *arr = malloc(sizeof(int)*(al+bl)) ; 
       while(e<al && e<bl)
       {
           if(a[q]>b[w])
           {
               arr[e] = b[w] ; 
               e++;w++ ; 
               
           }
           else if(a[q] <= b[w])
           {
               arr[e] =  a[q] ; 
               q++ ; e++ ; 
               
           }
          
       }
       if(q==al)
       {
           for(int po = al ; po<al+bl ; po++)
           {
               arr[po] = b[po]  ;
           }
       }
       else
       {
           for(int ko = bl ; ko<al+bl ; ko++)
           {
               arr[ko] = b[ko] ; 
           }
       }
       return arr ;  
    }
}