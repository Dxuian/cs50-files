#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int num  ; 
    node* pos ; 
    int loc ; 
}node  ; 


int main ()
{
    int a  ; 
    printf("press 1 for creating a lined list 2 for adding entries and 3 for exiting") ; 
    scanf("%i",&a) ; 
    switch (a) 
    {
        case 1 : 
        node* head  ; 
        node * n  = malloc(sizeof(node));
        printf("enter the number you wanna enter:  ") ; 
        int numbe ; 
        scanf("%i",&numbe) ; 
        n->num =  numbe 
        
        
        
    }
}