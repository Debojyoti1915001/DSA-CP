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
    ListNode*reverseNode(ListNode* head){
        ListNode*prev=NULL,*cur=head,*nxt=NULL;
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*q=reverseNode(slow);
        while(q&&head){
            if(q->val!=head->val)return false;
            q=q->next;
            head=head->next;
        }
        return true;
    }
};