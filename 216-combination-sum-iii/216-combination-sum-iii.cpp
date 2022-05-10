class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> temp,int k, int n,int ind,int sum){
        if(temp.size()>k||sum>n){
            return;
        }
        if(temp.size()==k){
            //cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<endl;
            if(sum==n)
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<=9;i++){
            temp.push_back(i);
            //cout<<i<<"->";
            sum+=i;
            solve(ans,temp,k,n,i+1,sum);
            sum-=i;
            temp.pop_back();    
        }
        
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,k,n,1,0);
        return ans;
    }
};