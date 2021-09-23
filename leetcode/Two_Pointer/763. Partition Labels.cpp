// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    bool check(vector<pair<int,int>>v){
        for(int i=0;i<26;i++){
            if(v[i].first!=v[i].second&&v[i].first!=0)return false;
        }
        return true;
    }
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int>ans;
        vector<pair<int,int>>v(26);
        for(auto c:s){
            v[c-'a'].first++;
            v[c-'a'].second++;
        }
        
        int i=0,j=0;
        while(j<n){
            v[s[j]-'a'].first=v[s[j]-'a'].first-1;
            while(!check(v)){
                j++;
                v[s[j]-'a'].first=v[s[j]-'a'].first-1;
            }
            ans.push_back(j-i+1);
            j++;
            i=j;
        }
        return ans;
    }
};


class Solution {
public:
    //First pass we record the last position for each letter. Second pass we keep the maximum position of the letters we have seen so far. If the pointer exceeds the maximum position, we found the part.
   vector<int> partitionLabels(string S) {
  vector<int> res, pos(26, 0);  
  for (auto i = 0; i < S.size(); ++i) pos[S[i] - 'a'] = i;
  for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
    idx = max(idx, pos[S[i] - 'a']);
     
    if (idx == i){
        res.push_back(i - last_i + 1);
        last_i=i+1;
    }
  }
  return res;
}
};