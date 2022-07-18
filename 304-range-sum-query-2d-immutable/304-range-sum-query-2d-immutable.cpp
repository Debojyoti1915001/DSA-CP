class NumMatrix {
public:
    int pre[205][205];
    NumMatrix(vector<vector<int>>& matrix) {
        memset(pre,0,sizeof(pre));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0&&j==0){
                    pre[0][0]=matrix[0][0];
                }
                else if(i==0){
                    pre[i][j]=matrix[i][j]+pre[i][j-1];
                }
                else if(j==0){
                    pre[i][j]=matrix[i][j]+pre[i-1][j];
                }else{
                    pre[i][j]=matrix[i][j]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==0&&col1==0){
            return pre[row2][col2];
        }
        else if(row1==0){
            return pre[row2][col2]-pre[row2][col1-1];
        }else if(col1==0){
            return pre[row2][col2]-pre[row1-1][col2];
        }else{
            return pre[row2][col2]-pre[row2][col1-1]-pre[row1-1][col2]+pre[row1-1][col1-1];
        }
        return 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */