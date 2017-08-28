#include<bits/stdc++.h>
using namespace std;
int ss(vector<int>& v, int n, int sum, vector<vector<int> >& dp){
  if(sum == 0)
    return 1;
  if(n == -1)
    return 0;
  if(dp[n][sum] == -1){
    if(sum-v[n] >= 0)
      dp[n][sum] = ss(v,n-1,sum,dp) || ss(v,n-1,sum-v[n],dp);
    else
      dp[n][sum] = ss(v,n-1,sum,dp);
  }
  return dp[n][sum];
}
int main(){
  int n,sum;
  cin >> n >> sum;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    cin >> v[i];
  vector<vector<int> > dp(n,vector<int>(sum+1,-1));
  if(ss(v,n-1,sum,dp))
    cout << "yes";
  else
    cout << "no";
  cout << endl;
  return 0;
}
