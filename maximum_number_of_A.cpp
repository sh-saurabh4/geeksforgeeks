#include<bits/stdc++.h>
using namespace std;
int mcount(int n,vector<int>& dp){
  if( n <= 6)
    return dp[n] = n;
  if(dp[n] == -1){//cout<<"world";
      dp[n] = INT_MIN;
      for(int i = 1; i <= n-3; i++){
        int temp = mcount(i,dp)*(n-i-1);
        dp[n] = max(dp[n],temp);//cout<<"hello";
      }
    }
  return dp[n];
}
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << mcount(n,dp);
    return 0;
}
