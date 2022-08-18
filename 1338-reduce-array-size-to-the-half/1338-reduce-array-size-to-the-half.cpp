class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int>m;
        for(auto &i:arr){
            m[i]++;
        }
        vector<int>v;
        for(auto &i:m){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0,c=0;
        for(auto &i:v){
            c+=i;
            ans++;
            if(c>=n/2){
                break;
            }
        }
        return ans;
            
    }
};