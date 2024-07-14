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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        ListNode* p=head, *prev=head;
        for(auto i:nums)mp[i]++;
        while(p!=NULL){
            if(mp[p->val]){
                if(p==head){
                    head=head->next;
                }else{
                    prev->next=p->next;
                }
            }else{
                prev=p;
            }
            p=p->next;
        }
        return head;
    }
};