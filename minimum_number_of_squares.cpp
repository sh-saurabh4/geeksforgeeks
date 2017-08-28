#include<bits/stdc++.h>
using namespace std;
int squ(vector<int>& a,int sum,int t,vector<int>& dp){
  if(sum < 0)
    return INT_MAX;
  if(sum == 0)
    return 0;
  if(dp[sum] == -1){
    dp[sum] = INT_MAX;//cout<<"hello";
    for(int i = 1; i <= t; i++){
      if(sum-a[i] >= 0 && dp[sum] > squ(a,sum-a[i],t,dp)+1)
        dp[sum] = squ(a,sum-a[i],t,dp)+1;
    }
  }
  return dp[sum];
}
int  main(){
  int sum;
  cin >> sum;
  int t = sqrt(sum);
  vector<int> a(t+1);
  for(int i = 0; i <= t; i++){
    a[i] = i*i;
    //cout<<a[i];
  }
  vector<int> dp(sum+1,-1);
  cout << squ(a,sum,t,dp);
  //for(int i = 0; i <= sum; i++)
  //  cout << dp[i]<<" ";
  return 0;
}
