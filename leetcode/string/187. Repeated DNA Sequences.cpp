// https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>m;
        vector<string>ans;
        int i=0,j=0;
        int n=s.length();
        string cur="";
        while(j<n){
            cur+=s[j];
            if(j-i+1<10){
                j++;    
            }else{
                m[cur]++;
                i++;
                cur.erase(0,1);
                j++;
            }
            
        }
        for(auto itr:m){
            if(itr.second>1){
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
};