#include <iostream>
using namespace std;
struct node{
int data;
node*next;
};
node*head;
node*reverse(node *head);
node*insert(node*head,int data);
void print(node*head);
int main(){
node *head=NULL;
head=insert(head,1);
head=insert(head,2);
head=insert(head,3);
head=insert(head,4);
head=insert(head,5);
print(head);
head=reverse(head);
print(head);
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
void print(node*head){
while(head!=NULL){
    cout<<head->data;
    head=head->next;
}
cout<<endl;
}
node* reverse(node*head){
node *current,*prev,*next;
current=head;
prev=NULL;
while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;

}
head=prev;
return head;
}
