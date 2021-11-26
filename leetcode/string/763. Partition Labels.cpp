// https://leetcode.com/problems/partition-labels/

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