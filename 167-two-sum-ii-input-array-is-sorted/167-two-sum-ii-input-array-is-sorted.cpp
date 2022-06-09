class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int lo=0,hi=v.size()-1;
        while(lo<hi){
            int sum=v[lo]+v[hi];
            if(sum==t)return {lo+1,hi+1};
            if(sum>t){
                hi--;
            }else{
                lo++;
            }
        }
        return {-1,-1};
    }
};