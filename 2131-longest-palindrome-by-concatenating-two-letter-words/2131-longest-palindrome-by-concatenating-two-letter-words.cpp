class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>m;
        int res=0,unpaired=0;
        for(auto &i:words){
            if(i[0]==i[1]){
                if(m[i]>0){
                    res+=4;
                    m[i]--;
                    unpaired--;
                }else{
                    m[i]++;
                    unpaired++;
                }
            }else{
                string rev=i;
                reverse(rev.begin(),rev.end());
                if(m[rev]>0){
                    res+=4;
                    m[rev]--;
                }else{
                    m[i]++;
                }
            }
        }
        if(unpaired>0)res+=2;
        return res;
    }
};