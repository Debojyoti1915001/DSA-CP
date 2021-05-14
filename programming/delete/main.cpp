#include <iostream>
using namespace std;
struct node{
int data;
node *next;
};
void del(int n);
void insert(int data);
void print();
node *head;
int main(){
head=NULL;
insert(1);insert(2);insert(3);insert(4);insert(5);
print();
int n;
cin>>n;
del(n);
print();
}
void del(int n){
node*temp=head;
if(n==1){
    head=temp->next;
    delete temp;
    return;
}
else{
for(int i=0;i<n-2;i++){
    temp=temp->next;
}
node*temp1=temp->next;
temp->next=temp1->next;
delete temp1;
}
}
void insert (int data){
node*temp=new node;
temp->data=data;
temp->next=head;
head=temp;

}
void print(){
node *temp=head;
while(temp!=NULL){
    cout<<temp->data<<"         ";
    temp=temp->next;
}
}
