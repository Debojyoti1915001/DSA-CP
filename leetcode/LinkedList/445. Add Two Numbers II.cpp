// https://leetcode.com/problems/add-two-numbers-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* reverse(ListNode* head){
        ListNode *p=NULL,*q=head,*r=NULL;
        while(q!=NULL){
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        return p;
    }
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        int s=0;
        int c=0;
         ListNode* temp;
         ListNode* head=NULL;
         ListNode* cur=NULL;
        first=reverse(first);
        second=reverse(second);
        while(first||second){
            s=c+(first?first->val:0)+(second?second->val:0);
            c=(s>9)?1:0;
            s=s%10;
            temp=new  ListNode(s);
            if(head==NULL){
                head=temp;
                cur=head;
            }else{
                cur->next=temp;
            }
            cur=temp;
            if(first)first=first->next;
            if(second)second=second->next;
        }
        if(c>0){
            temp=new ListNode(c);
            cur->next=temp;
            cur=temp;
        }
        head=reverse(head);
        return head;
    }
};