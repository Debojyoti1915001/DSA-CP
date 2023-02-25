class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0,mn=prices[0];
        for(int i=0;i<prices.size();i++){
            res=max(prices[i]-mn,res);
            mn=min(mn,prices[i]);
        }
        return res;
    }
};