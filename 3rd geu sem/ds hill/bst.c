#include <stdio.h>
#include <stdlib.h>

typedef struct tree // Structure Of a Tree Node
{
    int info;
    struct tree *left, *right;
} tree_type;

void insert(tree_type **rt, int num) // Function To Create Bst
{
    if (!(*rt))
    {
        *rt = (tree_type *)malloc(sizeof(tree_type));
        (*rt)->info = num;
        (*rt)->left = (*rt)->right = NULL;
    }

    else if (num < (*rt)->info)
    {
        insert(&(*rt)->left, num);
    }
    else
    {
        insert(&(*rt)->right, num);
    }
}

void preorder(tree_type *rt) // Preorder Traversal(Node,Left,Right)
{
    if (!rt)
        return;

    printf("->%d", rt->info);
    preorder(rt->left);
    preorder(rt->right);
}

void postorder(tree_type *rt) // Postorder Traversal(Left,Right,Node)
{
    if (!rt)
        return;
    postorder(rt->left);
    postorder(rt->right);
    printf("->%d", rt->info);
}

void inorder(tree_type *rt) // Inorder Traversal(Left,Node,Right)
{
    if (!rt)
        return;
    inorder(rt->left);
    printf("->%d", rt->info);
    inorder(rt->right);
}

int main()
{ // Main Function
    tree_type *rt = NULL;
    int choice, num;

    do
    {

        printf("1.Enter info of tree node \n2.Preorder Traversal \n3.Inorder Traversal \n4.Postorder Traversal\n5.Exit\n");
        printf("Enter your choice=");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter the info of root=");
            scanf("%d", &num);
            insert(&rt, num);
            break;

        case 2:
            preorder(rt);
            printf("\n");
            break;

        case 3:
            inorder(rt);
            printf("\n");

            break;
        case 4:
            postorder(rt);
            printf("\n");

            break;

        case 5:
            printf("Exiting..");
            break;

        default:
            printf("invalid choice\n");
            break;
        }
    } while (choice != 5);
}