

#include <stdio.h>
#include <stdlib.h>

typedef struct tree // Structure Of a Tree tree_type
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

void preorder(tree_type *rt) // Preorder Traversal(tree_type,Left,Right)
{
    if (!rt)
        return;

    printf("->%d", rt->info);
    preorder(rt->left);
    preorder(rt->right);
}

void postorder(tree_type *rt) // Postorder Traversal(Left,Right,tree_type)
{
    if (!rt)
        return;
    postorder(rt->left);
    postorder(rt->right);
    printf("->%d", rt->info);
}

void inorder(tree_type *rt) // Inorder Traversal(Left,tree_type,Right)
{
    if (!rt)
        return;
    inorder(rt->left);
    printf("->%d", rt->info);
    inorder(rt->right);
}

int count(tree_type *rt)
{
    if (!rt)
        return 0;
    else
        return 1 + count(rt->left) + count(rt->right);
}

tree_type *search(tree_type *rt, int key)
{
    if (!rt)
        return NULL;
    if (key == rt->info)
    {
        return rt;
    }
    else if (key < rt->info)
    {
        return search(rt->left, key);
    }
    else
    {
        return search(rt->right, key);
    }
}

void Insert(tree_type *rt, int key)
{
    tree_type *prev = NULL;
    while (rt)
    {
        prev = rt;
        if (key == rt->info)
        {
            printf("cannot insert already exist\n");
            return;
        }
        else if (key < rt->info)
        {
            rt = rt->left;
        }
        else
        {
            rt = rt->right;
        }
    }
    printf("inserted seccessfully\n");
    tree_type *new = (tree_type *)malloc(sizeof(tree_type));
    new->info = key;
    new->left = new->right = NULL;
    if (key < prev->info)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

// Find minimum value in right subtree
tree_type *findMin(tree_type *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
tree_type *deleteNode(tree_type *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->info)
        root->left = deleteNode(root->left, key);
    else if (key > root->info)
        root->right = deleteNode(root->right, key);

    else
    { // Found the node

        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL)
        {
            tree_type *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tree_type *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        tree_type *temp = findMin(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}

int main()
{ // Main Function
    tree_type *rt = NULL;
    int choice, num;
    int key, c;
    do
    {

        printf("1.Enter info of tree node \n2.Preorder Traversal \n3.Inorder Traversal \n4.Postorder Traversal\n5.Exit\n6.Count no.of nodes\n7.search for key\n8.insert in a binary tree.9.deletion \n");
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
        case 6:
            c = count(rt);
            printf("total no. of nodes=%d\n", c);
            break;
        case 7:
            printf("enter key=");
            scanf("%d", &key);
            tree_type *r = search(rt, key);
            if (!r)
                printf("key not exist\n");
            else
                printf("key found=%d\n", r->info);
            break;
        case 8:
            printf("enter info u want to insert=");
            scanf("%d", &key);
            Insert(rt, key);
            break;
        case 9
        :
            printf("enter info u want to delete=");
            scanf("%d", &key);
            tree_type *n = deleteNode(rt, key);
            if (rt)
            {
                printf("seccess deletion=%d\n", key);
            }
            else
                printf("not found\n");

            break;
        default:
            printf("invalid choice\n");
            break;
        }
    } while (choice != 5);
}