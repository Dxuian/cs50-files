#include <stdio.h>
void check(int ti[], int st[], int no);
int main()
{
    int a;
    scanf("%i", &a);
     for (int i = 0; i < a; i++)
    {
        int b;
        scanf("%i", &b);
        int ti[b], st[b];
        for (int j = 0; j < b; j++)
        {
            scanf("%i", &ti[j]);
        }
        for (int j = 0; j < b; j++)
        {
            scanf("%i", &st[j]);
        }
        check(ti, st, b);
    }

    
}
void check(int ti[], int st[], int no)
{
    int timestock =  0 , ki= 0  ;
    for( int i  =  0 ;  i< no  ; i++)
    {
        if(i!=0)
        {
            if(ti[i] - ti[i-1] - st[i] >=0)
            {
                ki++ ; 
            }
            
        }
        else
        {
            if(ti[i] - st[i] >= 0  )
            {
                ki++ ;
            }
        }
    }
    printf("%i\n",ki)  ; 
}
