class Solution {
public:
    int ans=INT_MAX;
    void solve(vector<int>& top,int t,int cur,int i){
        if(abs(t-cur)<abs(t-ans)){
            ans=cur;
        }else if(abs(t-cur)==abs(t-ans)){
            if(cur<ans)ans=cur;
        }
        if(i==top.size())return;
        solve(top,t,cur,i+1);
        solve(top,t,cur+top[i],i+1);
        solve(top,t,cur+2*top[i],i+1);
        
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for(auto b:baseCosts){
            solve(toppingCosts,target,b,0);
        }
        return ans;
    }
};