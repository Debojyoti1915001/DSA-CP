class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,res1=INT_MIN,res2=INT_MIN;
        int n=nums.size();
        for(auto &i:nums){
            if(res1==i){
                c1++;
            }else if(res2==i){
                c2++;
            }else if(c1==0){
                res1=i;
                c1++;
            }else if(c2==0){
                res2=i;
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto &i:nums){
            if(i==res1)c1++;
            if(i==res2)c2++;
        }
        if(c1>n/3&&c2>n/3)return {res1,res2};
        if(c1>n/3)return {res1};
        if(c2>n/3)return {res2};
        return {};
    }
};