class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        list<int>l;
        int i=0,j=0;
        while(j<nums.size()){
            while(nums[j]>l.back()&&l.size()!=0)l.pop_back();
            l.push_back(nums[j]);
            if(j-i+1<k)j++;
            else if(j-i+1==k){
                res.push_back(l.front());
                if(nums[i]==l.front())l.pop_front();
                j++,i++;
            }
        }
        return res;
    }
};