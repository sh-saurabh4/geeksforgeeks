#include<bits/stdc++.h>
using namespace std;
int fib(int n,vector<int>& dp){
  if (n == 1 || n == 2)
    return dp[n] = n;
  if(dp[n] == -1){
    dp[n] = fib(n-1,dp)+fib(n-2,dp);
  }
  return dp[n];
}
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    fib(n,dp);
    //for(int i = 0; i <= n; i++)
    cout << dp[n] <<" ";
    return 0;
}
