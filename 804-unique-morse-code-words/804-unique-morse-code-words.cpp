class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int>m;
        int ans=0;
        for(auto &i:words){
            string s;
            for(auto &j:i){
                s+=v[j-'a'];
            }
            if(!m.count(s))ans++;
            m[s]++;
        }
        return ans;
    }
};