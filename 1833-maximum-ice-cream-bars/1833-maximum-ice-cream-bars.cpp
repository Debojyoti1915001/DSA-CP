class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0,cur=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++){
            cur+=costs[i];
            if(cur>coins)break;
            ans++;
        }
        return ans;
    }
};