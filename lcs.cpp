#include<bits/stdc++.h>
using namespace std;
int lcs(string& str1, string& str2, int l1, int l2, vector<vector<int> >& dp){
	if(l1 == -1 || l2 == -1)
		return 0;
	if(dp[l1][l2] == -1){
		if(str1[l1] == str2[l2])
			dp[l1][l2] = 1+lcs(str1,str2,l1-1,l2-1,dp);
		else
			dp[l1][l2] = max(lcs(str1,str2,l1-1,l2,dp),lcs(str1,str2,l1,l2-1,dp));
	}
	return dp[l1][l2];
}
int main(){
	string str1,str2;
	int l1,l2;
	cin >> str1;
	cin >> str2;
	l1 = str1.length();
	l2 = str2.length();
	vector<vector<int> > dp(l1,vector<int>(l2,-1));
	cout << lcs(str1,str2,l1-1,l2-1,dp);
	return 0;
}
