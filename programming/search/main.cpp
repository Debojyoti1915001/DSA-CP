#include <iostream>

using namespace std;

struct BstNode{
int data;
BstNode *left;
BstNode *right;
};
BstNode *root;
BstNode*getnewnode(int data){
            BstNode*newnode=new BstNode();
            newnode->data=data;
            newnode->left=newnode->right=NULL;
            return newnode;
}
BstNode*insert(BstNode*root,int data){
if(root==NULL){
    root=getnewnode(data);
}
else if(data<=root->data){
    root->left=insert(root->left,data);
}
else{
    root->right=insert(root->left,data);
}
return root;
}
bool search(BstNode *root,int data){
if(root==NULL)return false;
else if(root->data==data)return true;
else if(data<=root->data)
    return search(root->left,data);
else return search(root->right,data);
}
int main(){
BstNode*root;
root=NULL;
insert(root,15);
insert(root,25);
insert(root,10);
if(search(root,10))
    cout<<"1";

//findmin(root);
}

