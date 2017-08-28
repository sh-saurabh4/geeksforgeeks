#include<bits/stdc++.h>
using namespace std;
int mcount(int n,int k,vector<vector<int> >& dp){
  if(n == 0)
    return 1;
  if(dp[n][k] == -1){
      dp[n][k] = 0;
      for(int i = 0; i <= k; i++){
        //if(!(n == 1 && i == 0))
          dp[n][k] += mcount(n-1,i,dp);
      }
  }
  return dp[n][k];
}
int main(){
    int n;
    cin >> n;
    vector<vector<int > > dp(n+2,vector<int>(10,-1));
    cout << mcount(n+1,9,dp);
    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= 9; j++){
        cout << dp[i][j] << " ";
      }cout << endl;
    }
    return 0;
}
