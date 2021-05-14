#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
};
void printInorder(node *node){
    if(node==NULL)return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}
void storeInorder(node*root,int inorder[],int *i){
    if(root==NULL)return;
    storeInorder(root->left,inorder,i);
    inorder[*i]=root->data;
    (*i)++;
    storeInorder(root->right,inorder,i);
}
int* merge(int arr1[],int arr2[],int m,int n){
    int *mergedArr=new int[m+n];
    int i=0,j=0,k=0;
    while(i<m&&j<n){
        if(arr1[i]<arr2[j])mergedArr[k++]=arr1[i++];
        else mergedArr[k++]=arr2[j++];
    }
    while(i<m){
        mergedArr[k++]=arr1[i++];
    }
    while(j<n){
        mergedArr[k++]=arr2[j++];
    }
    return mergedArr;
}
node *newNode(int t){
node* temp=new node();
temp->data=t;
temp->left=NULL;
temp->right=NULL;
return temp;
}
node* sortedArrayToBST(int arr[],int start,int end){
    if(start>end)return NULL;
    int mid=(start+end)/2;
    node *root=newNode(arr[mid]);
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);
    return root;
}
node* mergeTrees(node*root1,node*root2,int m,int n){
    int *arr1=new int[m];
    int i=0;
    storeInorder(root1,arr1,&i);
    int *arr2=new int[n];
    int j=0;
    storeInorder(root2,arr2,&j);
    int *mergedArr=merge(arr1,arr2,m,n);
    return sortedArrayToBST(mergedArr,0,m+n-1);
}
int main()
{
    node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);

    node *mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);

    return 0;
}
