class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sum=0;
        for(auto &i:possible){
            if(i==0)i-=1;
            sum+=i;
        }
        int cur=0;
        for(int i=0;i<possible.size()-1;i++){
            cur+=possible[i];
            sum-=possible[i];
            if(cur>sum)return i+1;
        }
        return -1;
    }
};