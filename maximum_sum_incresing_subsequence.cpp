#include<bits/stdc++.h>
using namespace std;
int res = 0;
int ms(vector<int>& v, int n, vector<int>& dp){
  if(n == -1)
    return 0;
  if(dp[n] == -1){
      int max = 0,temp;
      for(int i = 0; i < n; i++){
        temp = ms(v,i,dp);
        if(max < temp && v[i] < v[n])
          max = temp;
      }
      dp[n] = max + v[n];
      if(dp[n] > res)
        res = dp[n];
  }
  return dp[n];
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      cin >> v[i];
    vector<int> dp(n,-1);
    ms(v,n-1,dp);
    cout<<res;
    return 0;
}
