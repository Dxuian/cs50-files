 #include <stdio.h>
#include <stdlib.h>
#include<cs50.h>
typedef struct node
{
    int num;
    struct node *p;
    int l;
} node;
int main(void)
{
    node* h ;
    node* t ;
    node* al ;
    int i =1 ; 
    int p = get_int("enter the number of entries") ;
     for( h= NULL ; i<p ; i++)
     {
        node* n = (node*)malloc(sizeof(node)) ;
        h = n ;
        int a = get_int("enter the number  ") ; 
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
        
    }
    h = al ;

     for (node *tmp = h; tmp != NULL; tmp = tmp->p)
    {
        printf("%i\n", tmp->num);
    }
}
