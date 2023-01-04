class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<long long int,long long int>m;
        for(auto task:tasks){
            m[task]++;
        }
        int res=0;
        for(auto &[i,j]:m){
            if(j==1)return -1;
            if(j%3==0)res+=j/3;
            else if(j%3==2)res+=j/3+1;
            else res+=(j-4)/3+2;
        }
        return res;
    }
};