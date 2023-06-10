#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>
int hash(string a);
typedef struct node
{
    string s;
   struct  node *ne;
}node ;
void addentries(node n[]);

int main()
{
     node t[10] ;
    // setting it to zero
    for (int i = 0; i < 10; i++)
    {
        t[i].ne = NULL ;
        t[i].s = NULL ;
    }
    // now adding stuff to the thing
     int a  =  get_int("enter 1 for yes 0 for no ") ; 
    while (a==1)
    {
        addentries(t) ;
         a  =  get_int("enter 1 for yes 0 for no ") ; 
    }
    printf("thanks for using hash tables ");

}
void addentries(node n[])
{
    string a = get_string("enter the string you wanna enter   ");
    int in = hash(a) ;
    if (n[in].s == NULL)
    {
        n[in].s = a ;
        n[in].ne = NULL ;
    }
    else
    {
        node *b = (node *)malloc(sizeof(node));
        node *tem = &n[in] ;
        while ((tem->ne) != NULL)
        {
            tem = tem->ne ;
        }
        tem->ne = b ;
        b->ne = NULL;
         b->s = a ;
    }
    return  ; 
}

int hash(string a)
{
    int h = 0 ;
    int po = strlen(a) ;
    for (int i = 0; i < po; i++)
    {
        if (a[i] < 97 && a[i] >= 65)
        {
            h += (a[i] - 65) ; 
        }
        else
        {
            h += (a[i] - 97) ; 
        }
    }
    return (h / po)%10;
}