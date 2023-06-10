#include<stdio.h>
#include<stdlib.h>
#include<math.h>
       #include<cs50.h>
typedef struct node
{
    int num ;
    struct node* p ; 
    int l ; 
}node ; 
int main()
{
    
    int g = get_int("enter the number of entries  ") ; 
   
       node* h = NULL ; 
       node* t = NULL ;  
       for( int i =1 ;  i<= g  ; i++)
       {
           node* n = (node*)malloc(sizeof(node)) ; 
           int a  = get_int("enter the number "); 
           n->num =  a  ; 
           n-> p = NULL   ; 
           h= n  ; 
           if(i!=1)
           {
                n->p = t; 
           t = n ;  
           continue  ; 
           }
           t = n ; 
            
         
          
       }
    
     for (node *tmp = h; tmp != NULL; tmp = tmp->p)
    {
        printf("%i\n", tmp->num);
    }
    
    while(h!=NULL)
    {
        node* te = h->p; 
        free(h) ;
        h= te   ;
    }
    
    
    
    
}
