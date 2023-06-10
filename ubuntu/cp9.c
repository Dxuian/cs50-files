#include <stdio.h>
#include <string.h>
#include <strings.h>
int main()
{
    int a;
    scanf("%i", &a);
    int ar[a] ; 
    for (int i = 0; i < a; i++)
    {
        char g[200];
        scanf("%s", g);
        int ag = 0, br = 0;
        for (int j = 0; j < strlen(g); j++)
        {
            if (g[j] == 'a')
            {
                ag++;
            }
            else if(g[j]=='b')
            {
                br++;
            }
            
        }
        if (ag <= br)
            {
                ar[i] = ag;
            }
            else if (ag == 0 || br == 0)
            {
               ar[i] = 0 ;
            }
            else
            {
                ar[i] = br;
            }
    }
    for ( int p = 0 ; p < a ;p++)
    {
        printf("%i\n",ar[p]);
    }
}