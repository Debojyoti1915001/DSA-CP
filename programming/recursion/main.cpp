#include <iostream>
using namespace std;
struct node{
int data;
node*next;
};
node*head;
node*reverse(node *head);
node*insert(node*head,int data);
void print(node*p);
void reverseprint(node*p);
int main(){
node *head=NULL;
head=insert(head,1);
head=insert(head,2);
head=insert(head,3);
head=insert(head,4);
head=insert(head,5);
print(head);
reverseprint(head);
}
node*insert(node*head,int data){
node*temp=new node;
temp->data=data;
temp->next=NULL;
if(head==NULL){
    head=temp;
}
else{
    node*temp1=head;
    while(temp1->next!=NULL){
     temp1=temp1->next;
    }
        temp1->next=temp;

}
return head;
}
void print(node*p){
if(p==NULL){
    return;
}
else{
    cout<<p->data<<"    ";
    print(p->next);
}
 cout<<endl;
}
void reverseprint(node*p){
if(p==NULL){
    return;
}
else{
    reverseprint(p->next);

     cout<<p->data<<"   ";
}

}
