#include<bits/stdc++.h>
using namespace std;
int find(vector<vector<int> >& a,int n,vector<int>& dp){
  if( n == 0)
    return a[0][0];
  if(dp[n] == -1){
    dp[n] = a[0][n];
    for(int i = 0; i < n; i++){
      dp[n] = min(dp[n],find(a,i,dp)+a[i][n]);//cout<<"hello";
    }
  }//cout<<"eorld";
  return dp[n];
}
int main(){
    int n;
    cin >> n;
    vector<vector<int> > a(n,vector<int>(n));
    for(int i = 0; i < n; i++){
      for(int j = i; j < n; j++){
        cin >> a[i][j];
      }
    }
    vector<int> dp(n,-1);
    cout << find(a,n-1,dp);
    return 0;
}
