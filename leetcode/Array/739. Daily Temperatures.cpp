// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>v,ans;
        stack<pair<int,int>>stk;
        for(int i=temp.size()-1;i>=0;i--){
            if(stk.size()==0){
                v.push_back(-1);
            }else if(stk.size()!=0&&stk.top().first<=temp[i]){
                while(stk.size()!=0&&stk.top().first<=temp[i]){
                    stk.pop();
                }
                if(stk.size()==0){
                    v.push_back(-1);
                }else{
                    v.push_back(stk.top().second);
                }   
            }else{
                v.push_back(stk.top().second);
            }
            stk.push({temp[i],i});
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i]==-1)ans.push_back(0);
            else ans.push_back(v[i]-i);
        }
        return ans;
    }
};