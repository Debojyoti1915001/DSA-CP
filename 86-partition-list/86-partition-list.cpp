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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left=new ListNode(0),*right=new ListNode(0),*l=left,*r=right;
        while(head){
            ListNode*&cur=head->val<x?l:r;
                cur->next=head;
                cur=cur->next;
                head=head->next;
                cur->next=NULL;
        }
        l->next=right->next;
        return  left->next;
    }
};