#include <stdio.h>
void calculate(int x, int y,int no );
int main(void)
{
    // your code goes here
    int a;
    scanf("%i", &a);
    for (int i = 0; i < a; i++)
    {
        int b, c;
        scanf("%i %i", &b, &c);
        calculate(b,c,0) ;
    }
    return 0;
}
void calculate(int x, int y, int no)
{
    if (x == y)
    {
        printf("YES");
        return  ;
    }
    else if (y==x-1 || x==y-1)
    {
         printf("NO");
         return;
    }
    else if (x > y)
    {
        int d = (x - y) / 2;
        x -= d;
        y += d;
        calculate(x, y,no+1)   ;
    }
    else
    {
        int d = (y-x) / 2;
        x += d;
        y -= d;
        calculate(x,y, no+1);
    }
}
