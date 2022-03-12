// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head||!head->next||!head->next->next)return {-1,-1};
        int mx=INT_MIN,mn=INT_MAX,a,b,c,f;
        int l=-1,cnt=1;
        ListNode* p=head;
        head=head->next;
        while(head->next){
            a=p->val;
            b=head->val;
            c=head->next->val;
            if((b>a&&b>c)||(b<a&&b<c)){
                if(l==-1){
                    f=cnt;
                    l=cnt;
                }else{
                    mn=min(mn,cnt-l);
                    mx=cnt-f;
                     l=cnt;
                }
            }
            p=head;
            head=head->next;
            cnt++;
        }
        if(mn==INT_MAX||mx==INT_MIN)return {-1,-1};
        return {mn,mx};
    }
};