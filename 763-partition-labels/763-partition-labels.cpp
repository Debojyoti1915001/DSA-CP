class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>pos(26);//this holds the last position of every char
        for(int i=0;i<s.size();i++){
            pos[s[i]-'a']=i;
        }
        vector<int>ans;
        int last=-1,idx=INT_MIN;
        for(int i=0;i<s.size();i++){
            idx=max(idx,pos[s[i]-'a']);
            if(i==idx){
                ans.push_back(i-last);
                last=i;
            }
        }
        return ans;
    }
};