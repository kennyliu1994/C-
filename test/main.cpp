#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct lists
{
    int index;
    struct lists *parent;
    struct lists *child;
} list;
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

int main()
{
    list *temp1, *temp2;
    list *orig;
    orig = (list *)malloc(sizeof(list));
    orig->index = -1;
    orig->parent = NULL;
    orig->child = NULL;
    temp1 = orig;
    printf("%d\n", temp1);
    printf("%d\n", temp1->parent);
    printf("%d\n", temp1->child);
    printf("%d\n", temp1->index);
    insert(temp1, 0);
    printf("%d\n", temp1);
    printf("%d\n", temp1->parent);
    printf("%d\n", temp1->child);
    printf("%d\n", temp1->index);
    temp1 = temp1->child;
    printf("%d\n", temp1);
    printf("%d\n", temp1->parent);
    printf("%d\n", temp1->child);
    printf("%d\n", temp1->index);
    insert(temp1, 1);
    printf("%d\n", temp1);
    printf("%d\n", temp1->parent);
    printf("%d\n", temp1->child);
    printf("%d\n", temp1->index);
    temp1 = temp1->child;
    printf("%d\n", temp1);
    printf("%d\n", temp1->parent);
    printf("%d\n", temp1->child);
    printf("%d\n", temp1->index);
}