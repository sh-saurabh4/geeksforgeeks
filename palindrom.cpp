#include<bits/stdc++.h>
using namespace std;
string expand(string str,int i,int j){
	int n = str.length();
	string res;
	while( i>=0 && j<n && str[i] == str[j]){
		//res  = str.substr(i,j-i+1);
		//cout<<res;
		i--;
		j++;
	}
	i++;
	j--;
	res = str.substr(i,j-i+1);
	return res;
}	


int main(){
	string str;
	getline(cin,str);
	int n = str.length();
	if(n == 0)
		return 0;
	string longest = str.substr(0,1);
	for(int i=0; i<n-1;i++){
		string s1 = expand(str,i,i);
		if(s1.length() > longest.length())
			longest = s1;
		string s2 = expand(str,i,i+1);
		if(s2.length() > longest.length())
			longest = s2;
	}
	cout<<longest;
	return 0;
}
		
