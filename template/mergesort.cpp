// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int

void Merge(vector<int>&v,int low,int mid,int high,vector<int>&temp){

    int k=low;
    int i=low;
    int j=mid+1;
    while(i<=mid and j<=high){
        if(v[i]<=v[j]){
            temp[k++]=v[i];
            i++;
        }
        else{
            temp[k++]=v[j];
            j++;
        }
    }
    while(i<=mid){
        temp[k++]=v[i++];
    }
    while(j<=high){
        temp[k++]=v[j++];
    }
    for(int i=low;i<=high;i++){
        v[i]=temp[i];
    }

}
void mergesort(vector<int>&v,int low,int high,vector<int>&temp){
    if(low>=high){
        return;
    }
    int mid=(low+high)>>1;
    mergesort(v,low,mid,temp);
    mergesort(v,mid+1,high,temp);
    Merge(v,low,mid,high,temp);
}

 
int main()
{
     int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   vector<int> temp(n);
   mergesort(v,0,n-1,temp);
   for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
   }
   cout<<endl;
} 

