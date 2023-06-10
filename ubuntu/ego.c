#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<cs50.h>
typedef struct node
{
    int num;
    struct node *p;
    int l;
} node;
int main()
{
     int al ;
    node* h = NULL  ;
    printf("enter the number for 1st node") ; 
    node * n = malloc(sizeof(node)) ; 
    int a ;
    scanf("%i",&a)  ;
    n->num  =a  ;
    n->l = 1 ; 
    n->p = NULL ;
    h = n ; 
     int i= 1;
     for( node* temp = n  ; temp!=NULL && i<=4; temp= temp->p)
     {
      n = malloc(sizeof(node)) ; 
   
     printf("enter the number for %ith node   ",i) ; 
    scanf("%i",&al)  ;
    printf("\n") ; 
    n->num  =al  ;
    n->l = i ; 
     n->p = NULL ;
     temp->p = n ; 
i++;     
     }
      for (node *tmp = h; tmp != NULL; tmp = tmp->p)
    {
        printf("%i\n", tmp->num);
    }
    
    return 0;
}