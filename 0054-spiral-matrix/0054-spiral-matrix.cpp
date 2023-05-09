class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int top=0,down=v.size()-1,left=0,right=v[0].size()-1,dir=0;
        vector<int> ans;
        while(top<=down&&right>=left){
            if(dir==0){
                for(int i=left;i<=right;i++)ans.push_back(v[top][i]);
                top++;
            }else if(dir==1){
                for(int i=top;i<=down;i++)ans.push_back(v[i][right]);
                right--;
            }else if(dir==2){
                for(int i=right;i>=left;i--)ans.push_back(v[down][i]);
                down--;
                
            }else if(dir==3){
                for(int i=down;i>=top;i--)ans.push_back(v[i][left]);
                left++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};