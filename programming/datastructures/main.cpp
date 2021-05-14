 #include<iostream>
 #include<queue>
 using namespace std;
 struct Node{
     char data;
     Node *left;
     Node *right;
 };
 void levelorder(Node *root){
     if(root==NULL)
         return;
     queue<Node*> q;
     q.push(root);
     while(!q.empty()){
         Node *current=q.front();
         cout<<current->data<<" ";
         if(current->left!=NULL)q.push(current->left);
         if(current->right!=NULL)q.push(current->right);
         q.pop();
     }
 }
 Node *insert(Node *root,char data){
     if(root==NULL){
         root=new Node();
         root->data=data;
         root->left=root->right=NULL;
     }
     else if(data<=root->data)root->left=insert(root->left,data);
     else root->right=insert(root->right,data);
     return root;
 }
 int main(){
     Node *root=NULL;
    root=insert(root,'M');
     levelorder(root);
 }
