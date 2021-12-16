// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    vector<int> NSL(vector<int>v){
        vector<int> ans;
        stack<pair<int,int>>stk;
        for(int i=0;i<v.size();i++){
            if(stk.size()==0){
                ans.push_back(-1);
            }else if(stk.top().first>=v[i]){
                while(stk.size()!=0&&stk.top().first>=v[i]){
                    stk.pop();
                }
                if(stk.size()==0)ans.push_back(-1);
                else ans.push_back(stk.top().second);
            }else{
                ans.push_back(stk.top().second);
            }
            stk.push({v[i],i});
        }
        return ans;
    }
    vector<int> NSR(vector<int>v){
        vector<int> ans;
        stack<pair<int,int>>stk;
        for(int i=v.size()-1;i>=0;i--){
            if(stk.size()==0){
                ans.push_back(v.size());
            }else if(stk.top().first>=v[i]){
                while(stk.size()!=0&&stk.top().first>=v[i]){
                    stk.pop();
                }
                if(stk.size()==0)ans.push_back(v.size());
                else ans.push_back(stk.top().second);
            }else{
                ans.push_back(stk.top().second);
            }
            stk.push({v[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        
        int ans=0;
        vector<int>v(m),left,right;
        for(int i=0;i<n;i++){
            if(i==0){
            for(int j=0;j<m;j++){
                  if(matrix[i][j]=='1')v[j]=1;
            }
            left=NSL(v);
            right=NSR(v);
            for(int k=0;k<m;k++){
                ans=max(ans,(right[k]-left[k]-1)*v[k]);
            }
            }else{
             for(int j=0;j<m;j++){
                  if(matrix[i][j]=='0')v[j]=0;
                 else v[j]=v[j]+1;
            }
             left=NSL(v);   
            right=NSR(v);
            for(int k=0;k<m;k++){
                ans=max(ans,(right[k]-left[k]-1)*v[k]);
                
            }   
            }
            
        }
        return ans;
    }
};