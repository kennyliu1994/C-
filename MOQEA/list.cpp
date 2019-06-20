#include "iostream" //was not declared in this scope

#include "global.h"

void insert(list *node, int x)
{
    list *temp;
    if (node == NULL)
    {
        printf("\n Error!! asked to enter after a NULL pointer, hence exiting \n");
        exit(1);
    }
    temp = (list *)malloc(sizeof(list));
    temp->index = x;
    temp->child = node->child;
    temp->parent = node;
    if (node->child != NULL)
    {
        node->child->parent = temp;
    }
    node->child = temp;
    return;
}

/* Delete the node NODE from the list */
list *del(list *node)
{
    list *temp;
    if (node == NULL)
    {
        printf("\n Error!! asked to delete a NULL pointer, hence exiting \n");
        exit(1);
    }
    temp = node->parent;
    temp->child = node->child;
    if (temp->child != NULL)
    {
        temp->child->parent = temp;
    }
    free(node);
    return (temp);
}