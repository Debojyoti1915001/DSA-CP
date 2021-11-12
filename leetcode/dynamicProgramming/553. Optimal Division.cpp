// https://leetcode.com/problems/optimal-division/

Using some simple math we can find the easy solution of this problem. 
Consider the input in the form of [a,b,c,d], now we have to set priority of operations to maximize a/b/c/d. 
We know that to maximize fraction p/qp/q, qq(denominator) should be minimized. 
So, to maximize a/b/c/da/b/c/d we have to first minimize b/c/d. 
Now our objective turns to minimize the expression b/c/d.

There are two possible combinations of this expression, b/(c/d) and (b/c)/d.

b/(c/d)        (b/c)/d = b/c/d
(b*d)/c        b/(d*c)
d/c            1/(d*c)
Obviously, d/c > 1/(d*c)d/c>1/(d∗c) for d>1d>1.

You can see that second combination will always be less than first one for numbers greater than 11. 
So, the answer will be a/(b/c/d). Similarly for expression like a/b/c/d/e/f... answer will be a/(b/c/d/e/f...).

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1)return to_string(nums[0]);
        if(nums.size()==2)return to_string(nums[0])+"/"+to_string(nums[1]);
        string ans=to_string(nums[0])+"/("+to_string(nums[1]);
        for(int i=2;i<nums.size();i++){
            ans+="/"+to_string(nums[i]);
        }
        ans+=")";
        return ans;
    }
};