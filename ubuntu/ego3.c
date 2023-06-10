#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

node *new_node(int num, node* next)
{
    node *n = malloc(sizeof(node));
    n->num  = num;
    n->next = next;
    return n;
}

int main()
{
    node *list = NULL;
    for (int i = 0; i < 4; i++)
    {
        int num = get_int("Enter number for %ith node: ", i);
        list = new_node(num, list);
    }

    for (node *n = list; n != NULL; n = n->next)
    {
        printf("Node nr: %d\n", n->num);
    }
}