#include<bits/stdc++.h>
using namespace std;
int ed(int k, int n, vector<vector<int> >& dp){
  if( k == 0)
    return 0;
  if( n == 1)
    return k;
  if(dp[k][n] == -1){
    int min = INT_MAX,temp;
    for(int i = 1; i <= k; i++){
      temp = max(ed(k-i,n,dp),ed(i-1,n-1,dp));
      if(temp < min)
        min = temp;
    }
    dp[k][n] = min+1;
  }
  return dp[k][n];
}
int main(){
    int k,n;
    cin >> k >> n;
    vector<vector<int> > dp(k+1,vector<int>(n+1,-1));
    cout << ed(k,n,dp);
    return 0;
}
