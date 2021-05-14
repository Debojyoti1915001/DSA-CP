#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	long k;
	cin>>k;
	for(size_t i=0;i<s.length();i++){
		if(isalpha(s[i])==1){
			if((((s[i]>='a')&&(s[i]<='z'-k))||((s[i]>='A')&&(s[i]<='Z'-k))){
				s[i]=s[i]+k;
			}
			else if((s[i]>'z'-k)&&(s[i]<='z')){
				s[i]=s[i]+k-'z';
			}
			else{
				s[i]=s[i]+k-'Z';
			}

		}
		else if(isdigit(s[i])==1){
			if(s[i]<=9-k){
				s[i]=s[i]+k;
			}
			else{
				s[i]=s[i]+k-9;
			}
		}
		else{
			s[i]=s[i];
		}

	}
	cout<<s;


}
