// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even=0,odd=0;
        for(auto p:position){
            if(p&1){
                odd++;
            }else{
                even++;
            }
        }
        return min(odd,even);
    }
};