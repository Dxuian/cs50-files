#include <stdio.h>
void c1(int b, int c, int ar[]);
int main(void)
{
    // your code goes here
    unsigned int a;
    scanf("%i", &a);
    for (int i = 0; i < a; i++)
    {
        unsigned int b;
        unsigned int c;
        scanf("%i%i", &b, &c);
         int ar[b];
        for (int j = 0; j < b; j++)
        {
            scanf("%i", &ar[j]);
            
        }
        
        
        int max = -1;
        int pos = 0;
    for (int is = 0; is < b; is++)
    {
        if (ar[is] < c)
        {
            max = ar[is];
        }
    }
     if(max==-1)
        {
            printf("0\n");
            break  ; 
        }

    for (int ia = 0; ia < b; ia++)
    {
        if (ar[ia] == max)
        {
            pos = ia;
        }
       
    }
    if (max!= 0)
    {
        printf("%i\n", pos + 1);
    }
    }
    return 0;
}