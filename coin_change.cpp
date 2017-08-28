#include<bits/stdc++.h>
using namespace std;
int cc(vector<int>& v,int size,int n,vector<vector<int> >& dp){
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;
  if (size < 0)
    return 0;
  if(dp[size][n] == -1){
      dp[size][n] = cc(v,size-1,n,dp)+cc(v,size,n-v[size],dp);
  }
  return dp[size][n];
}
int main(){
    int size,n;
    cin >> size;
    vector<int> v(size);
    for(int i = 0; i < size; i++)
      cin >> v[i];
    cin >> n;
    vector<vector<int> > dp(size,vector<int>(n+1,-1));
    cout << cc(v,size-1,n,dp);
    return 0;
}
