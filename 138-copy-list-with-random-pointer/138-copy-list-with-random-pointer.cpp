/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//first solution using hashmap
//second one in constant space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node *p=head,*res=NULL;
        //create a copy mf
        while(p){
            Node*newNode=new Node(p->val);
            newNode->next=p->next;
            p->next=newNode;
            p=p->next->next;
        }
        //A A' B B'
        p=head;
        while(p){
            p->next->random=p->random?p->random->next:NULL;
            p=p->next->next;
        }
        p=head->next;
        res=head->next;
        while(head){
            head->next=head->next->next;
            p->next=(p->next)?p->next->next:NULL;
            p=p->next;
            head=head->next;
        }
        return res;
    }
};