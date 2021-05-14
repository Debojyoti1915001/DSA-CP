// #include<iostream>
// #include<vector>
#include <bits/stdc++.h>
using namespace std;
int func(vector<int> v,int n){
	reverse(v.begin(), v.end());
	for (auto i = v.begin(); i != v.end(); ++i) {
        if (*i % 2 != 0) {
            v.erase(i);
            i--;
        }
    }
	if(v.size()==1){
		return v[0];

	}
	else
	func(v,n/2);

}
int main(){
	int test,n;
	cin>>test;
	while(test--){
		vector<int> v;
		cin>>n;
		for(int i=2;i<n;i+=2){
			v.push_back(i);
		}
		int k=func(v,n);
		cout<<k<<endl;
		}
	}
