// https://leetcode.com/problems/add-two-numbers/

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
        int carry=0;
        int f=0;
        ListNode *head=NULL,*ptr=NULL;
        while(l1&&l2){
            int x=l1->val+l2->val+carry;
            if(x>=10){
                carry=1;
                x=x-10;
            }else carry=0;
            if(f==0){
                f=1;
                head=new ListNode(x);
                head->next=NULL;
                ptr=head;
            }else{
                ListNode *node=new ListNode(x);
                node->next=NULL;
                ptr->next=node;
                ptr=node;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int x=l1->val+carry;
            if(x>=10){
                carry=1;
                x=x-10;
            }else carry=0;
            ListNode *node=new ListNode(x);
                node->next=NULL;
                ptr->next=node;
                ptr=node;
            l1=l1->next;
        }
        while(l2){
            int x=l2->val+carry;
            if(x>=10){
                carry=1;
                x=x-10;
            }else carry=0;
            ListNode *node=new ListNode(x);
                node->next=NULL;
                ptr->next=node;
                ptr=node;
            
            l2=l2->next;
        }
        if(carry==1){
            ListNode *node=new ListNode(1);
                node->next=NULL;
                ptr->next=node;
                ptr=node;
        }
       return head;
    }
};