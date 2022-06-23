// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>res;
    void dfs(vector<vector<int>> &m, int n,int i,int j,string cur){
        if(i>=n||j>=n||i<0||j<0||m[i][j]==0)return;
        m[i][j]=0;
        if(i==n-1&&j==n-1){
            res.push_back(cur);
        }
        dfs(m,n,i+1,j,cur+'D');
        dfs(m,n,i,j+1,cur+'R');
        dfs(m,n,i-1,j,cur+'U');
        dfs(m,n,i,j-1,cur+'L');
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        dfs(m,n,0,0,"");
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends