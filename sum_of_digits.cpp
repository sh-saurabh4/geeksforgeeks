#include<bits/stdc++.h>
using namespace std;
int sum(int n,vector<int>& dp){
  dp[0] = 0;
  for(int i = 1; i <= n; i++){
    int x = i%10;
    int y = i/10;
    int t = 0;
    if(y == 0)
      t = x;
    else
      t = x+dp[y]-dp[y-1];
    dp[i] = t + dp[i-1];
  }
  return dp[n];
}
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << sum(n,dp);
    return 0;
}
