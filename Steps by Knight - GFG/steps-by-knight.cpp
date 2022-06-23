// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    private:
	struct cell{
		int x;
		int y;
		int steps;
	};
    public:
    
   	bool isValid(int x, int y, int N){
		return (x >=0 and x < N and y >=0 and y < N);
	}
	
	//Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
		KnightPos[0]--;
		KnightPos[1]--;
		TargetPos[0]--;
		TargetPos[1]--;
		
		vector<vector<bool>>vis(N, vector<bool>(N, false));
		
		vector<vector<int>>dxy = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
		queue<cell>q;
		q.push({KnightPos[0], KnightPos[1], 0});
		vis[KnightPos[0]][KnightPos[1]] = true;
		
		while(!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int steps = q.front().steps;
			q.pop();
			if(x == TargetPos[0] and y == TargetPos[1])
				return steps;
			for(int i = 0; i < dxy.size(); i++)
			{
				int n_x = x + dxy[i][0];
				int n_y = y + dxy[i][1];
				if(isValid(n_x, n_y, N) and !vis[n_x][n_y])
				{
					q.push({n_x, n_y, steps+1});
					vis[n_x][n_y] = true;
				}
			}
		}
		return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends