class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>dp(105);//an vector to store the values as in pascals triangle
        dp[0]=poured;//here we consider that the whole is poured on to the first glass
        for(int i=1;i<=query_row;i++){
            for(int j=i;j>=0;j--){
                double curTop=max(0.0, (dp[j] - 1) / 2);//what the top value contains will be equally split bw j and j+1
                //everytime we are adding a index i to the array which is empty initially 
                dp[j] =curTop ;
                dp[j+1]+=curTop;//since we have already calculated for j+1
            }
        }
        return min(1.0,dp[query_glass]);
    }
};