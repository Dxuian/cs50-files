#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<math.h>

int re(int a[], int x ) ; 
int main()
{
    int arr[]  = {5,24,233,2,23,234,2,24,23,243234,234,2,4,22,32,45467,387,689,467,35,44};
 int i  = sizeof(arr)/sizeof(arr[0]) ; 
    printf("%lu    ",sizeof(arr)/sizeof(arr[0])) ; 
    re(arr,i-1) ; 
}

int re(int a[], int x )
{
  if(x==0)
  {
      printf("%i   ",a[x]) ; 
      return 0 ; 
  }
  else if(x>0) 
  {
      printf("%i  ",a[x]) ;
      return re(a , x-1) ; 
  }
  else 
  {
      return  0   ; 
  }
 
}
