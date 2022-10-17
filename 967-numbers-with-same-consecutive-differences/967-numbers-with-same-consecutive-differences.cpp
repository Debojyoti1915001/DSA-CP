class Solution {
public:
    vector<int>ans;
    void solve(string cur,int n,int k,int last){
        if(n==0){
            ans.push_back(stoi(cur));
            return;
        }
        if(k==0){
            solve(cur+to_string(last),n-1,k,last);
        }else{
            if(last-k>=0){
                solve(cur+to_string(last-k),n-1,k,last-k);
            }
            if(last+k<=9){
                solve(cur+to_string(last+k),n-1,k,last+k);
            }
        }
        
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string cur;
        for(int i=1;i<=9;i++){
            cur=to_string(i);
            solve(cur,n-1,k,i);
        }
        return ans;
    }
};