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
    void reorderList(ListNode* head) {
        //if head or head->next==NULL i.e. no or one nodes are present
        if(!head||!head->next)return;
        //find the middle of the code
        ListNode* slow=head,* fast=head->next,*p1,*p2;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*head2=slow->next;
        slow->next=NULL;
        p2=head2->next;
        head2->next=NULL;
        while(p2){
            p1=p2->next;
            p2->next=head2;
            head2=p2;
            p2=p1;
        }
        for(p1=head,p2=head2;p1;){
            auto t=p1->next;
            p1->next=p2;
            p1=p1->next;
            p2=t;
        }
        
    }
};