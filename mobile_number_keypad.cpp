#include<bits/stdc++.h>
using namespace std;
int mnk(int k,int n,vector<vector<int> >& dp){
  if(n == 1){
    //cout << "hello" << n << k;
    return dp[n][k] = 1;
  }
  if(dp[n][k] == -1){
    switch(k){
      case 1:
            return dp[n][k] = mnk(1,n-1,dp)+mnk(2,n-1,dp)+mnk(4,n-1,dp);
      case 2:
            return dp[n][k] = mnk(1,n-1,dp)+mnk(2,n-1,dp)+mnk(3,n-1,dp)+mnk(5,n-1,dp);
      case 3:
            return dp[n][k] = mnk(2,n-1,dp)+mnk(3,n-1,dp)+mnk(6,n-1,dp);
      case 4:
            return dp[n][k] = mnk(1,n-1,dp)+mnk(5,n-1,dp)+mnk(4,n-1,dp)+mnk(7,n-1,dp);
      case 5:
            return dp[n][k] = mnk(2,n-1,dp)+mnk(4,n-1,dp)+mnk(5,n-1,dp)+mnk(6,n-1,dp)+mnk(8,n-1,dp);
      case 6:
            return dp[n][k] = mnk(3,n-1,dp)+mnk(5,n-1,dp)+mnk(9,n-1,dp)+mnk(6,n-1,dp);
      case 7:
            return dp[n][k] = mnk(4,n-1,dp)+mnk(8,n-1,dp)+mnk(7,n-1,dp);
      case 8:
            return dp[n][k] = mnk(9,n-1,dp)+mnk(8,n-1,dp)+mnk(7,n-1,dp)+mnk(5,n-1,dp)+mnk(0,n-1,dp);
      case 9:
            return dp[n][k] = mnk(6,n-1,dp)+mnk(8,n-1,dp)+mnk(9,n-1,dp);
      case 0:
            return dp[n][k] = mnk(0,n-1,dp)+mnk(8,n-1,dp);
    }
  }
  return dp[n][k];
}
int main(){
  int n;
  cin >> n;
  vector<vector<int> > dp(n+1,vector<int>(10,-1));
  mnk(0,n,dp);mnk(1,n,dp);mnk(2,n,dp);mnk(3,n,dp);mnk(4,n,dp);mnk(5,n,dp);
  mnk(6,n,dp);mnk(7,n,dp);mnk(8,n,dp);mnk(9,n,dp);
  int temp = 0;
  for(int j = 1; j <= n; j++){
    temp = 0;
    for(int i = 0; i < 10; i++){
      temp += dp[j][i];
    }
    cout << temp << endl;
  }
  return 0;
}
