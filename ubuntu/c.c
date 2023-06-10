#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a;
    scanf("%i", &a);
    long *r = (long *)malloc(a * sizeof(long));
    long s[1];
    for (int i = 0; i < a; i++)
    {
        scanf("%li", &s[0]);
        for (int d = 1; d <= s[0]; d++)
        {
            if ((d == 6 && d < 7))
            {
                r[i]++;
            }
            else if ((d > 7 && (d % 7) == 6)) {
                    r[i]++ ; 
            }
        }
    }
    for (int p = 0; p < a; p++)
    {
        printf("%li\n", r[p]);
    }
    free(r);
    return 0;
}
