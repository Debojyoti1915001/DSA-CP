#include<bits/stdc++.h>
using namespace std;
int countTriplets(vector<vector<int>> &p){
    int count=0;
    for(int i=0;i<p.size();i++){
            unordered_map<int,int>d;
            for(int j=0;j<p.size();j++){
                int dist=pow(p[j][1]-p[i][1],2)+pow(p[j][0]-p[i][0],2);
                if(d[dist]>0){
                    count+=2*d[dist];
                }
                d[dist]++;
            }
    }
    return count;
}
int main(){

    int n;
    cin>>n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
      int a,b;
      cin>>a>>b;
      vector<int>v;
      v.push_back(a);
      v.push_back(b);
      arr.push_back(v);
    }
    cout<<countTriplets(arr);
    return 0;
}
