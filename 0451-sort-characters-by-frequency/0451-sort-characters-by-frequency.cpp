map<char,int> m;
class Solution {
public:
    static bool comp(pair<char,int> a,pair<char,int> b){
        if(a.second!=b.second)
            return a.second>b.second;
        return a.first<b.second;
    }
    string frequencySort(string s) {
        map<char,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        vector<pair<char,int>> m1(m.begin(),m.end());
        sort(m1.begin(),m1.end(),comp);
        string output;
        for(auto x:m1){
            int t=x.second;
            while(t--){
                output.push_back(x.first);
            }
        }
        return output;
    }
};