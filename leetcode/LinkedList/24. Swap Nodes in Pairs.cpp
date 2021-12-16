// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy,*p=head,*nx;
        while(p&&p->next){
            nx=p->next->next;
            prev->next=p->next;
            p->next->next=p;
            p->next=nx;
            prev=p;
            p=nx;
        }
        return dummy->next;
    }
};