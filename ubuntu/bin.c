#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <ncurses.h>
#include <time.h>
#include <cs50.h>
int re(int a[], int mid, int left, int right, int s);
int main()
{
    //20 elements
    int a[] = { 8,12, 22, 33, 44, 55, 76, 78, 89, 96, 105, 116, 127, 133, 146, 156, 168, 173, 184,199};
    int se = get_int("enter the number youre looking for      ");
    int x = (sizeof(a) / sizeof(a[0])-1), y = 0, z;

   z = ceil((y+x+1)/2) ;
    re(a, z, y, x, se);
  
}
int re(int a[], int mid, int left, int right, int s)
{
    if (a[mid] == s)
    {
        printf("FOUND\n");
        return  0  ;
    }
    // search left
    else if (a[mid] >  s)
    {
        //notdone
        //even
        //left
        if ((right+1) % 2 == 0)
        {
             right=mid-1 ;
             mid = ceil((left+right)/2);
             if(left==right)
             {
                printf("NOT FOUND \n") ; return  0  ; 
             }
             
             
             return re(a, mid, left, right, s);
        }
        //notdone
        //odd
        //
        else if((right+1)%2==1)
        {
            right= mid-1 ;
            mid = ceil((left+right)/2);
            if(left==right)
             {
                printf("NOT FOUND \n") ; return  0  ; printf("NOT FOUND \n") ;
             }
            return re(a, mid, left, right, s);
        }
        else
        {
            printf("NOT FOUND \n") ;
            return 0;

        }
    }
    // search right
    else if (a[mid] <  s)
    {
        //notdone
        //even
        if ((right+1) % 2 == 0)
        {
            left= mid + 1;
             mid = ceil((left+right)/2);
             if(left==right)
             {
                printf("NOT FOUND \n") ; return  0  ; printf("NOT FOUND \n") ;
             }
            return re(a, mid, left, right, s);
        }
        //notdone
        //odd
        else if((right+1)%2==1)
        {
             left= mid + 1;
             mid = ceil((left+right)/2);
             if(left==right)
             {
                 printf("NOT FOUND \n") ;return  0  ; printf("NOT FOUND \n") ;
             }
            return re(a, mid, left, right, s);
        }
        else
        {
           printf("NOT FOUND \n") ; printf("NOT FOUND \n") ;
            return 0;
        }
    }
    else
    {
        printf("NOT FOUND \n") ;
        return 0;
    }
}
