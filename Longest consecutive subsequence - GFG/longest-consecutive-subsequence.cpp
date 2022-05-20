// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      //Your code here
      unordered_map<int,int>m;
      for(int i=0;i<n;i++)m[a[i]]++;
      int ans=1;
      for(int i=0;i<n;i++){
          if(m[a[i]-1]==0){
              int val=a[i];
              int temp=0;
              while(m[val]!=0){
                  temp++;
                  val++;
              }
              ans=max(ans,temp);
          }
      }
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends