#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int>& weigths,vector<int>& value,int n,int w,vector<vector<int> >& dp){
  if( n == -1)
    return 0;
  if(dp[n][w] == -1){
    if(w-weigths[n] >= 0)
      dp[n][w] = max(knapsack(weigths,value,n-1,w,dp),value[n]+knapsack(weigths,value,n-1,w - weigths[n],dp));
    else
      dp[n][w] = knapsack(weigths,value,n-1,w,dp);
  }
  return dp[n][w];
}
int main(){
  int n,w;
  cin >> n;
  vector<int> weigths(n),value(n);
  for(int i = 0; i < n; i++)
    cin >> weigths[i];
  for(int i = 0; i < n; i++)
    cin >> value[i];
  cin >> w;
  vector<vector<int> > dp(n,vector<int>(w+1,-1));
  cout << knapsack(weigths,value,n-1,w,dp);
  return 0;
}
