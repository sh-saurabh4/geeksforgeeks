#include<bits/stdc++.h>
using namespace std;
int coins(vector<int>& a,int v,int n,vector<int>& dp){
  if(v == 0)
    return 0;
  if(dp[v] == -1){
    dp[v] = INT_MAX;
    for(int i = 0; i < n; i++){
      if(v-a[i] >= 0)
        dp[v] = min(dp[v],coins(a,v-a[i],n,dp)+1);
    }
  }
  return dp[v];
}
int main(){
    int n,v;
    cin >> n >> v;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> dp(v+1,-1);
    cout << coins(a,v,n,dp);
    //for(int i = 0; i <= v; i++)
    //  cout << dp[i] << " ";
    return 0;
}
