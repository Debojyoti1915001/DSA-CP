// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends

int minSwap(int *arr, int n, int k) {
    // Complet the function
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k)cnt++;
    }
    int replaceCnt=0;
    for(int i=0;i<cnt;i++){
        if(arr[i]>k){
            replaceCnt++;
        }
    }
    int i=0,j=cnt,ans=replaceCnt;
    while(j<n){
        if(arr[j]>k){
            replaceCnt++;
        }
        if(arr[i]>k){
            replaceCnt--;
        }
        ans=min(ans,replaceCnt);
        i++,j++;
    }
    return ans;
}
