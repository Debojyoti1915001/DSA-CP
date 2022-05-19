// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long mx=arr[0];
	    long long mn=arr[0];
	    long long ans=arr[0];
	    for(int i=1;i<n;i++){
	        //if the cur ele is neg swap the numbers 
	        long long x=arr[i];
	        if(x<0)swap(mx,mn);
	        //otherwise check the  greater of cur ele and cur ele times max obtained so far
	        mx=max(x,mx*x);
	        mn=min(x,mn*x);
	        ans=max(ans,mx);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends