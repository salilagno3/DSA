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
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->l))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        isBST(root->r);
    }
    else
        return 1;
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
    root = createNode(5);
    n1 = createNode(3);
    n2 = createNode(6);
    n3 = createNode(1);
    n4 = createNode(4);
    // linking nodes
    root->l = n1;
    root->r = n2;
    n1->l = n3;
    n1->r = n4;
    while (1)
    {
        printf("Enter:\n1.Check if it is a BST\n2.Pre order Traversal\n3.Postorder Traversal\n4.Inorder Traversal\n5.EXIT\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (isBST(root) == 1)
                printf("\nBinary search tree\n");
            else
                printf("\nNot a binary search tree\n");
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            postOrder(root);
            break;
        case 4:
            inOrder(root);
            break;
        case 5:
            printf("\nExitting...");
            exit(0);
        default:
            printf("Not valid");
        }
    }
}