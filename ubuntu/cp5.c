#include <stdio.h>
#include <math.h>
void check(int s, int b, int c, int d);
int main()
{
    int a;
    scanf("%i", &a);
    for (int i = 0; i < a; i++)
    {
        float s, b, c, d;

        scanf("%f%f%f%f", &s, &b, &c, &d);
        if ((pow((s / b), 2)) == (pow((c / d), 3)))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        // check(s,b,c,d)  ;
    }
}
// void check(int s , int b , int c , int d )
// {
//     if((pow((s/b),2)) == (pow ((c/d),3)))
//     {
//         printf("YES\n") ;
//     }
//     else
//     {
//         printf("NO\n");
//     }
// }