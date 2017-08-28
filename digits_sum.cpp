#include<bits/stdc++.h>
using namespace std;
int mcount (int n,int sum,vector<vector<int> >& dp){
  if(n == -1){
    if(sum == 0)
      return 1;
    return 0;
  }
  if(dp[n][sum] == -1){
    dp[n][sum] = 0;
    for(int i = 0; i <= 9; i++){
      if(!(n == 0 && i == 0) && sum-i >= 0)
      dp[n][sum] += mcount(n-1,sum-i,dp);
    }
  }
  return dp[n][sum];
}
int main(){
    int n,sum;
    cin >> n >> sum;
    vector<vector<int> > dp(n,vector<int>(sum+1,-1));
    cout << mcount(n-1,sum,dp);
    return 0;
}
