#include<stdio.h>
#include<strings.h>
#include<string.h>
int main(void)
{
    // your code goes here
    int a;
    scanf("%i", &a);
    for (int i = 0; i < a; i++)
    {
        int b;
        scanf("%i", &b);
        char c[b];
        scanf("%s", c);
        int fin = 0, start = 0;
        for (int j = 0; j < strlen(c); j++)
        {

            if (c[j] == 'H' && start == 0 && j != strlen(c) - 1)
            {
                start = 1;
            }
            else if (c[j] == 'T' && start == 1)
            {
                start = 0;
            }
            else if ((c[j] == 'T' && (start == 0)) || (c[j] == 'H' && j == strlen(c) - 1) ||(c[j]=='H' && start==1))
            {
                fin = 1;
                break;
            }
        }
        if (fin == 1)
        {
            printf("Invalid\n");
        }
        else
        {
            printf("Valid\n");
        }
    }
    return 0;
}
