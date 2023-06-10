#include<stdio.h>
int main (void)
{
    int d[]={3,2,4,8,4,1,9};
    int temp  =0  ;
   for( int  j= 0 ; j <3 ; j++)
       {
           for ( int k = 0;  k<3; k++)
           {
               if(d[j]< d[k])
               {

               }
               else if (d[j]> d[k] && j!=k)
               {
                  temp =  d[j] ; 
                    d[j] = d[k] ;
                    d[k] = temp ; 
                   
               }
           }
       }
    return 0 ;
}