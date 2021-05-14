#include <iostream>

using namespace std;

void insert(int data,int n);
void print();
struct Node{
int data;
Node *next;
};
Node *head;
int main(){
head=NULL;
int t;
cout<<"Enter the number of terms    :";
cin>>t;
for(int i=0;i<t;i++){
    int data,pos;
    cout<<"Enter the data and pos   :";
    cin>>data>>pos;
    insert(data,pos);
}
print();
}
void insert(int data,int n){
Node *temp=new Node;
temp->data=data;
temp->next=NULL;
if(n==1){
    temp->next=head;
    head=temp;
    return;
}
else{
    Node *temp1=head;
    for(int i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
}
}
void print(){
Node*temp=head;
while(temp!=NULL){
    cout<<temp->data<<"     ";
    temp=temp->next;
}
cout<<endl;
}
