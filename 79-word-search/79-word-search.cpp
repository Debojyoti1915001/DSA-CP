class Solution {
public:
    int n,m;
    vector<pair<int,int>>dir{{0,1},{0,-1},{-1,0},{1,0}};
    bool dfs(vector<vector<char>>& g, string word,int i,int j,int k){
        if(k==word.size())return true;
        if(i>=n||j>=m||i<0||j<0||word[k]!=g[i][j])return false;
        for(int ind=0;ind<4;ind++){
            int ni=i+dir[ind].first;
            int nj=j+dir[ind].second;
            char c=g[i][j];
            g[i][j]='#';
            if(dfs(g,word,ni,nj,k+1))return true;
            g[i][j]=c;
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0))return true;
            }
        }
        return false;
    }
};