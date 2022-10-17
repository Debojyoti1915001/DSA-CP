class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                int temp=m[i][j];
                m[i][j]=m[n-1-j][i];
                m[n-1-j][i]=m[n-i-1][n-j-1];
                m[n-i-1][n-j-1]=m[j][n-i-1];
                m[j][n-i-1]=temp;
            }
        }
    }
};