#include <iostream>
using namespace std;
struct node{
int val;
node *next;
};
int main(){
int n,k,g;
cin>>n>>k>>g;
int dead=0;
node *head=NULL,*last=NULL;
for(int i=0;i<n;i++){
    node*temp=new node;
    temp->val=i+1;
    if(!head){
        head=temp;
        last=temp;
    }
    else{
        last->next=temp;
        last=temp;
    }
}
}
 last->next = head;
 node *gun = head;
 while(gun->val != g){
 gun = gun->next;
}
while(1){
int to_kill = (gun->val)%k;
while(to_kill && dead<n-1){
nn* t ;
t = gun->next;
gun->next = gun->next->next;
free(t);
dead++; --to_kill;
}
if(dead == n-1) break;
gun = gun->next;
}
cout<<gun->val<<endl;

}
