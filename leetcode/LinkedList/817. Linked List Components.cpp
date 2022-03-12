// https://leetcode.com/problems/linked-list-components/

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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>um;
        for(auto num:nums){
            um[num]++;
        }
        int c=0;
        while(head){
            if(um[head->val]!=0){
                while(head&&um[head->val]!=0){
                    head=head->next;
                }
                c++;
            }else{
                head=head->next;
            }
        }
        return c;
    }
};