#include<bits/stdc++.h>
using namespace std;
int bc(int n,int k,vector<vector<int> >& dp){
  if (n == k || k == 0)
    return 1;
  if(dp[n][k] == -1){
    dp[n][k] = bc(n-1,k-1,dp)+bc(n-1,k,dp);
  }
  return dp[n][k];
}

int main(){
  int n,k;
  cin >> n >> k;
  vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
  cout << bc(n,k,dp);
  return 0;
}
