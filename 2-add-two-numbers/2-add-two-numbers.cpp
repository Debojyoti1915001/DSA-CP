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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,c=0;
        ListNode*dummy=new ListNode(0),*p=dummy;
        while(l1||l2||c){
            sum=0;
            sum+=(l1?l1->val:0);
            sum+=(l2?l2->val:0);
            sum+=c;
            p->next=new ListNode(sum%10);
            p=p->next;
            c=sum/10;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        return dummy->next;
    }
};