class Solution {
public:
    bool check(int i,int j,int n,int m){
        if(i>=n||j>=m||i<0||j<0)return false;
        return true;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        int moves=0;
        q.push({e[0],e[1]});
        while(q.size()){
            int sz=q.size();
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                if((i==0||j==0||i==n-1||j==m-1)&&!(i==e[0]&&j==e[1]))return moves;
                if(check(i+1,j,n,m)&&maze[i+1][j]!='+'){q.push({i+1,j});maze[i+1][j]='+';}
                if(check(i,j+1,n,m)&&maze[i][j+1]!='+'){q.push({i,j+1});maze[i][j+1]='+';}
                if(check(i-1,j,n,m)&&maze[i-1][j]!='+'){q.push({i-1,j});maze[i-1][j]='+';}
                if(check(i,j-1,n,m)&&maze[i][j-1]!='+'){q.push({i,j-1});maze[i][j-1]='+';}
            }
            moves++;
        }
        return -1;
    }
};