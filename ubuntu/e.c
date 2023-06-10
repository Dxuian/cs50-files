#include<stdio.h>
#include<stdlib.h>
int main()
{
     typedef struct node
     {
         int num ; 
         struct node* p ; 
         int pos ; 
     }node ; 
     node* head  = NULL ;  
      printf("enter 1 for creating a linked list 2 for adding new entries linearly") ; 
      int x; 
      scanf("%i",&x) ;
      node* n  ; 
    
      switch (x)  
      {
          case 1 :
          
          n = (node*) malloc(sizeof(node));
          head =  n  ; 
          int jk ; 
          scanf("%i", &jk) ;
          n->num =  jk ; 
          n->pos = 1 ; 
          n->p = NULL; 
          break ; 
          case 2 : 
          kpk:
          printf("enter the number of entries you wanna make:  ");
          int a  ; 
          scanf("%i", &a) ; 
          int i   = 0 ;
          for( node* temp = head  ;  temp!=NULL   ; temp= temp->p)
          {
              node* nb = (node*)malloc(sizeof(node)) ;
              
              nb->pos =  i+1 ; 
              nb->p = NULL;
              int ase ; 
              scanf("%i", &ase) ; 
              nb->num = ase  ;
              node* y  = head  ; 
              while(y!=NULL)
              {
                 y =  y->p ; 
                 
              }
              y->p = nb->p  ; 
              
          }
            for (node *tmp = head; tmp != NULL; tmp = tmp->p)
    {
        printf("%i\n", tmp->num);
    }
          break ; 
          
      } 
      goto kpk ; 
    
        
     
        
      }
