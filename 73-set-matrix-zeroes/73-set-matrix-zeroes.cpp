class Solution {
public:
    void setZeroes(vector<vector<int>>& M) {
        int n=M.size();
        int m=M[0].size();
        int f1=0,f2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0){
                    if(i==0)f1++;
                    if(j==0)f2++;
                    M[i][0]=0;
                    M[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(M[0][j]==0||M[i][0]==0)
                M[i][j]=0;
            }
        }
        for(int i=0;i<n&&f2;i++){
                M[i][0]=0;
        }
        for(int j=0;j<m&&f1;j++){
                M[0][j]=0;
        }
    }
}; 