class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int c=0;
        vector<int>ans;
        for(int i=num.size()-1;i>=0;i--){
            int cur=k%10+num[i]+c;
            k=k/10;
            ans.push_back(cur%10);
            c=cur/10;
        }
        while(k){
            int cur=k%10+c;
            k=k/10;
            ans.push_back(cur%10);
            c=cur/10;
        }
        if(c)ans.push_back(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};