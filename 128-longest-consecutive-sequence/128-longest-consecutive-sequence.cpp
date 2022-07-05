class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size()==0)return 0;
        sort(v.begin(),v.end());
        int ans=1,c=1;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1])continue;
            if(v[i]-v[i-1]==1)c++;
            else {
                ans=max(ans,c);
                c=1;
            }
        }
        ans=max(ans,c);
        return ans;
    }
};