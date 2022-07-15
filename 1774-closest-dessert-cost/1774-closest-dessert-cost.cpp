class Solution {
public:
    
    int ans = INT_MAX;
    
    void helper(vector<int>& toppingCosts, int target, int currSum, int index)
    {
        if(abs(target-ans) > abs(target-currSum)) ans = currSum;
        else if(abs(target-ans) == abs(currSum-target)) ans = min(ans, currSum);
        
        if(index == toppingCosts.size()) return;
        
        helper(toppingCosts, target, currSum, index+1);
        helper(toppingCosts, target, currSum+toppingCosts[index], index+1);
        helper(toppingCosts, target, currSum+2*toppingCosts[index], index+1);
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {
        for(int i=0; i<baseCosts.size(); i++)
            helper(toppingCosts, target, baseCosts[i], 0);
        
        return ans;
    }
};