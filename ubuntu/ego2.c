#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
typedef struct node 
{
    int num ; 
    struct 
    node* next  ;
}node ; 

node *new_node(int num, node* next) ; 

int main()
{
    node *list = NULL;
    for (int i = 0; i < 4; i++)
    {
        int num = get_int("Enter number for %ith node: ",i) ;
        list = new_node(i, list);
    }

    for (node *n = list; n != NULL; n = n->next)
    {
        printf("Node nr: %d     ", n->num);
    }
}
node *new_node(int num, node* next)
{
    node *n = malloc(sizeof(node));
    n->num  = num;
    n->next = next;
    return n;
}