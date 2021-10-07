// https://leetcode.com/problems/decode-xored-array/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>arr{first};
        for(int i=0;i<encoded.size();i++){
            arr.push_back(arr.back()^encoded[i]);
        }
        return arr;
    }
};