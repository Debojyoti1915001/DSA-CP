class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,n=nums.size(),num=-1;
        for(int i=0;i<n;i++){
            if(c==0){
                num=nums[i];
                c++;
            }else if(num==nums[i]){
                c++;
            }else c--;
        }
        return num;
    }
};