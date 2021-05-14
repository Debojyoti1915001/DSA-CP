#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    struct node* root = NULL;
    int n,rvalue;
    printf("Enter the number of nodes= ");
    scanf("%d",&n);
    printf("Enter the value at root node= ");
     scanf("%d",&rvalue);
    root = insert(root, rvalue);
    printf("Enter the values to be inserted=\n");
    for(int i=0;i<n-1;i++){
        int val;
        scanf("%d",&val);
        insert(root,val);
    }
    printf("Inorder traversal of the binary search tree is:\n");
    inorder(root);

    return 0;
}
