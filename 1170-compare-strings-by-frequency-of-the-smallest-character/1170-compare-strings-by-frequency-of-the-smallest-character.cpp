class Solution {
public:
    int solve(string s){
        vector<int>cnt1(26);
            for(auto &j:s){
                cnt1[j-'a']++;
            }
            for(int j=0;j<26;j++){
                if(cnt1[j]!=0){
                    return cnt1[j];
                }
            }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>cnt,ans;
        for(auto &i:words){
            cnt.push_back(solve(i));
        }
        sort(cnt.begin(),cnt.end());
        for(auto i:cnt){
            // cout<<i<<" ";
        }
        for(auto &i:queries){
            int cur=solve(i);
            int bb=upper_bound(cnt.begin(),cnt.end(),cur)-cnt.begin();
            int val=cnt.size()-bb;
            ans.push_back(val);
        }
        return ans;
    }
};