//Mriganka Bharali 1915014
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%6d", root->data);
        inorder(root->right);
    }
}
void postorder(struct node* root) {
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%6d", root->data);
}

void preorder(struct node* root) {
	if (root == NULL)
		return;

	printf("%6d", root->data);
	preorder(root->left);
	preorder(root->right);
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right,data);
    return node;
}


int main()
{
    struct node* root = NULL;
    int n,rvalue;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the value at root node: ");
     scanf("%d",&rvalue);
    root = insert(root, rvalue);
    printf("Enter the values to be inserted: \n");
    for(int i=0;i<n-1;i++){
        int val;
        scanf("%d",&val);
        insert(root,val);
    }

    printf("\nInorder traversal of the given tree: \n");
    inorder(root);
    printf("\nPreorder traversal of the given tree: \n");
    preorder(root);
    printf("\nPostorder traversal of the given tree: \n");
    postorder(root);

    return 0;
}
