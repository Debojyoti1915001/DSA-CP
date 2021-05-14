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
int main(){
BstNode*root;
root=NULL;
insert(root,15);
insert(root,25);
insert(root,10);

}
