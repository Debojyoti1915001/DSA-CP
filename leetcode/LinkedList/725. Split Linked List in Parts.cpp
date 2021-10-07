// https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int c=0;
        vector<ListNode*>ans;
        ListNode*p=head,*prev=head;
        while(p!=NULL){
            p=p->next;
            c++;
        }
        
        int rem=c%k;
        int per=c/k;
        p=head;
        while(k--){
            ans.push_back(p);
            int moves=per;
            while(moves>0){
                if(p){
                    prev=p;
                    p=p->next;
                }
                moves--;
            }
            if(rem>0){
                rem--;
                if(p){
                    prev=p;
                    p=p->next;
                }
            }
            if(p){
                prev->next=NULL;
                prev=p;
            }
        }
        return ans;
    }
};