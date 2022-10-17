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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k==1)return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy,*cur=dummy,*nxt=dummy;
        int c=0;
        while(cur->next){
            cur=cur->next;
            c++;
        }
        while(c>=k){
            cur=prev->next;
            nxt=cur->next;
            for(int i=1;i<k;i++){
                cur->next=nxt->next;
                nxt->next=prev->next;
                prev->next=nxt;
                nxt=cur->next;
            }
            prev=cur;
            c-=k;
        }
        return dummy->next;
    }
};