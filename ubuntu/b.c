#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    struct node *p;
    int l;
} node;
int main(void)
{
    node *h;
    node *t;
    node* al  ;
    int i = 1;
    int a;
    node *n;
    while (  i < 5)
    {
         n = (node *)malloc(sizeof(node)) ;
        h = n;
    
        printf("enter a number you wanna use   ") ;  
        scanf("%i", &a);
        n->num = a;
        n->p = NULL;
        if (i == 1)
        {
            t = n;
            al = n ; 
        }
        if (i != 1)
        {
            t->p = n;
            t = t->p;
        }
        i++ ;
    }
    h = al  ;
    for (node *tmp = h; tmp != NULL; tmp = tmp->p)
    {
        printf("%i\n", tmp->num);
    }
}
