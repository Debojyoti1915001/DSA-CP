#include<iostream>
using namespace std;
struct Node{
int data;
Node *next;
};
Node *head;
void insert(int data);
void print();
int main(){
head=NULL;
int i, n,x;
cout<<"\nHow many numbers you want to add   :";
cin>>n;
for(i=0;i<n;i++){
    cout<<"\nEnter the number   :";
    cin>>x;
    insert(x);
    print();
}
}
void insert(int data){
Node *temp=new Node;
temp->data=data;
temp->next=head;
head=temp;
}
void print(){
Node *temp=head;
while(temp!=NULL){
    cout<<temp->data<<"     ";
    temp=temp->next;
}
}
