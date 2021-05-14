// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here
        queue<int> q;
        int sum=0;
        int minCnt=n;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            cnt++;
            while(q.size()!=0&&sum-q.front()>x){
                    sum=sum-q.front();
                    cout<<"Case#"<<i<<" "<<q.front();
                    q.pop();
                    cnt--;
            }
            cout<<endl;
            if(sum>x)
            minCnt=min(minCnt,cnt);
            cout<<i<<":"<<minCnt<<" "<<endl;
            q.push(arr[i]);
        }
        return minCnt;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends
