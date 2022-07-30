class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int b=-prices[0]-fee;
        int s=0;
        for(int i=1;i<prices.size();i++){
            int pb=b;
            int ps=s;
            b=max(pb,ps-prices[i]-fee);
            s=max(ps,pb+prices[i]);
        }
        return s;
    }
};