#include <stdio.h>
#include <ctype.h>
void check(char b[]);
int main()
{
    int a;
    scanf("%i", &a);
    for (int is = 0; is < a; is++)
    {
        char b[400];
        scanf("%s", b);

        int sym = 0;
        for (int k = 0; k < 400; k++)
        {
            if (b[k] == '(')
            {
                sym++;
            }
        }
         int start  = asdf
        for (int ys = 0; ys < sym; ys++)
        {
            for (int i = 0; i < 400; i++)
            {
                
                
                for  ( int p = 0 ;  p< 400 ;p++)
                {
                   if(b[p] = '(')
                   {
                       asdf++ ; 
                   }
                }
                for ( int ip  = 0 ;  ip<400 ; ip++)
                {
                    if(b[p] = '(')
                   {
                       asdf++ ; 
                   }
                   if(asdf==0)
                   {
                       start =  asdf  ; 
                   }
                }
                
                
                if (b[i] == '(' && isalpha(b[i + 1]) != 0 && isalpha(b[i + 3]) != 0 && b[i + 4] == ')')
                {
                    char y = b[i + 2];
                    char z = b[i + 3];
                    b[i + 2] = z;
                    b[i + 3] = y;
                    for (int ka = i; ka < 400; ka++)
                    {
                        b[ka] = b[ka + 1];
                    }
                    for (int po = i; po < 400; po++)
                    {
                        b[po + 3] = b[po + 4];
                    }
                }
            }
            for (int ij = 0; ij < 400; ij++)
            {
                printf("%c", b[ij]);
            }
        }
    }
}

// void check(char b[])
// {
//   for (int i = 0; i < 400; i++)
//         {
//             if (b[i] == '(' && isalpha(b[i + 1]) != 0 && isalpha(b[i + 3]) != 0 && b[i + 4] == ')')
//             {
//                 char y = b[i + 2];
//                 char z = b[i + 3];
//                 b[i + 2] = z;
//                 b[i + 3] = y;
//                 for (int ka = i; ka < 400; ka++)
//                 {
//                     b[ka] = b[ka + 1];
//                 }
//                 for (int po = i; po < 400; po++)
//                 {
//                     b[po + 3] = b[po + 4];
//                 }
//             }
//         }
//         for (int ij = 0; ij < 400; ij++)
//         {
//             printf("%c", b[ij]);
//         }
// }