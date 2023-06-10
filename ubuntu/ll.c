#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int xs = 1;
    int y = 2;

    printf("x is %i, y is %i\n", xs, y);
    swap(&y, &xs);
    printf("x is %i, y is %i\n", xs, y);
    int[10] x[10]  ; 
    for(int i = 0 ;  i<10   ; i++)
    {
        x[i]  = i   ; 
    }
}

void swap(int *b, int *a)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}