class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        if(c.size()%2)return {};
        unordered_map<int,int>m;
        for(auto &i:c)m[i]++;
        sort(c.begin(),c.end(),greater<int>());
        vector<int>res;
        for(auto &i:c){
            if(i%2==0){
                if(m[i]>0&&m[i/2]>0){
                m[i]--;
                m[i/2]--;
                if(m[i]>=0&&m[i/2]>=0)
                res.push_back(i/2);
            }
            }
            if(res.size()==c.size()/2)return res;
        }
        return {};
    }
};