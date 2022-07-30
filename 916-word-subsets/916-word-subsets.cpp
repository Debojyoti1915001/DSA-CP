class Solution {
public:
    vector<int>counter(string s){
        vector<int>cnt(26);
        for(auto i:s){
            cnt[i-'a']++;
        }
        return cnt;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>cnt(26),temp(26);
        for(auto i:words2){
            temp=counter(i);
            for(int j=0;j<26;j++){
                cnt[j]=max(temp[j],cnt[j]);
            }
        }
        for(auto i:words1){
            temp=counter(i);
            int f=0;
            for(int j=0;j<26;j++){
                if(temp[j]<cnt[j]){
                    f=1;
                    break;
                }
            }
            if(!f)ans.push_back(i);
        }
        return ans;
    }
};