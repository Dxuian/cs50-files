#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  struct   node* ne ;
     int nu ;
}node ;
int main()
{
    int k = 0 ;
   struct node* temp =NULL;
   struct node* head =NULL;
    while (k<10)
    {
        node* n = malloc(sizeof(node));
        n->nu = k ;
        if(temp==NULL)
        {
            k++;
            temp=n ;
            head=n ;
        }
        else
        {
                k++;
            temp->ne=n;
            temp=temp->ne;
        }
    }
 struct    node* tem=head ;
    while(tem!=NULL)
    {
        printf("%i\n",tem->nu) ;
        tem=tem->ne ;
    }
}