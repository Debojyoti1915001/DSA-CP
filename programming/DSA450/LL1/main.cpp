// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;

    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }

    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;

        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);

        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin>> pos;
        loopHere(head,tail,pos);

        removeLoop(head);

        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
void removeL(Node* p,Node* head){
    Node* p1=p;
    Node* p2=p;
    int k=1;
    while(p1->next!=p2){
        k++;
        p1=p1->next;
    }
    p1=head;
    p2=head;
    while(k--){
        p2=p2->next;
    }
    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }
    while(p1!=p2->next){
        p2=p2->next;
    }
    p2->next=NULL;
}
void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *p1=head,*p2=head;
    while((p1->next->next!=NULL&&p1->next!=NULL)){
        p1=p1->next->next;
        p2=p2->next;
        if(p1==p2){
            removeL(p1,head);
            break;
        }
    }
}
