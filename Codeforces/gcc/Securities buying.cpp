#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;
 
int securitiesBuying(int z,int s[],int n)
{
    int ans=0;
   // participants code here
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    int val=0;
    for(int i=1;i<=n;i++){
        pq.push({s[i-1],i});
    }
    while(pq.size()&&z>val){
        auto t=pq.top();
        ans++;
        pq.pop();
        val+=t.first;
        t.second--;
        if(t.second)pq.push({t.first,t.second});
    }
    if(z>=val)return ans;
    return ans-1;
}
 
int main(){
 
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
 
 
while (iss >> data)
    input_data.push_back(data);
 
int n= input_data.size();
 
 
 int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
 
 
int no_of_stocks_purchased = securitiesBuying(z,security_value,n);
cout << no_of_stocks_purchased;
 
 
 
}
 
 
