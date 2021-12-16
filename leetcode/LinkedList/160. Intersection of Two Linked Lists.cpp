// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *a=headA,*b=headB;
        while(a){
            a=a->next;
            l1++;
        }while(b){
            b=b->next;
            l2++;
        }
        a=headA,b=headB;
        if(l1>=l2){
            int diff=l1-l2;
            while(diff--)a=a->next;
            while(a!=b){
                a=a->next;
                b=b->next;
            }
            
        }else{
            int diff=l2-l1;
            while(diff--)b=b->next;
            while(a!=b){
                a=a->next;
                b=b->next;
            }
        }
        return a;
    }
};