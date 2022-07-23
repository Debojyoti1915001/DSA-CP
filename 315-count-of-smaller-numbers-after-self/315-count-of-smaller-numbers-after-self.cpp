class Solution {
public:
    #define itr vector<vector<int>>::iterator
    void merge_count(itr l,itr r,vector<int>&count){
        if(r-l<=1)return;
        auto m=l+(r-l)/2;
        merge_count(l,m,count);
        merge_count(m,r,count);
        itr i=l;
        itr j=m;
        for(itr i=l,j=m;i<m;i++){
            while(j<r&&( (*i)[0]> (*j)[0] )){
                j++;
            }
            count[(*i)[1]]+=j-m;
        }
        inplace_merge(l,m,r);
    } 
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(vector<int>({nums[i],i}));
        }
        vector<int>count(nums.size(),0);
        merge_count(temp.begin(),temp.end(),count);
        return count;
    }
};