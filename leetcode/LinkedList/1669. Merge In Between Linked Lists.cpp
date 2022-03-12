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
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
        ListNode*p=l1,*q=NULL;
        int k=b-a+2;
        a--;
        while(a--){
            p=p->next;
        }
        q=p;
        while(k--){
            
            q=q->next;
        }
        p->next=l2;
        while(l2->next!=NULL){
            l2=l2->next;
        }
        l2->next=q;
        return l1;
    }
};