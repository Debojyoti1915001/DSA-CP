class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=0;
        for(int i=0;i<gain.size();i++){
            if(i!=0){
                gain[i]=gain[i]+gain[i-1];
            }
            mx=max(mx,gain[i]);
        }
        return mx;
    }
};