//Pritom Pegu 1915018
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
        printf("%d ", root->key);
        inorder(root->right);
    }
}
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
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

    printf("Inorder traversal of the given tree \n");
    inorder(root);
      int no;
      printf("\nEnter the number of nodes to be deleted\n");
      scanf("%d",&no);
      while(no--){
    int k;
    printf("\nEnter the value of the node to be deleted:\n");
    scanf("%d",&k);
    root = deleteNode(root, k);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
      }
    return 0;
}
