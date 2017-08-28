#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>& str,int l,vector<int>& dp){
	if(l == 0)
		return 1;
	if(dp[l] == -1){
		int temp = 0;
		for(int i = 0; i < l; i++){
			int data = lis(str,i,dp);
			if(str[i] < str[l]){
				if(temp < data)
					temp = data;
			}
		}
		dp[l] = temp + 1;
	}
	return dp[l];
}

int main(){
	
	//vector<int> str;
	int l,res=-1;
	cin >> l;
	vector<int> str(l);
	for(int i = 0; i < l; i++)
		cin >> str[i];
	vector<int> dp(l,-1);
	lis(str,l-1,dp);
	for(int i = 0; i < l; i++)
		if(dp[i] > res)
			res = dp[i];
	cout << res;
	return 0;
}
	
	
