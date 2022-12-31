#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *l;
    struct node *r;
};
struct node *createNode(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preOrder(root->l);
        preOrder(root->r);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->l);
        postOrder(root->r);
        printf("%d", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->l);
        printf("%d", root->data);
        inOrder(root->r);
    }
}

void main()
{
    int n;
    struct node *root;
    struct node *n1;
    struct node *n2;
    struct node *n3;
    struct node *n4;
    struct node *n5;
    // creating nodes
    root = createNode(4);
    n1 = createNode(1);
    n2 = createNode(6);
    n3 = createNode(5);
    n4 = createNode(2);
    // linking nodes
    root->l = n1;
    root->r = n2;
    n1->l = n3;
    n1->r = n4;
    printf("\nEnter :\n1.Preorder Traversal\n2.Postorder Traversal\n3.Inorder Traversal\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        preOrder(root);
        break;
    case 2:
        postOrder(root);
        break;
    case 3:
        inOrder(root);
        break;
    default:
        printf("Not valid");
    }
}