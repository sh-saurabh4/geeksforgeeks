#include<bits/stdc++.h>
using namespace std;
int x,y;
int points(vector<vector<int> >& a,int i,int j,vector<vector<int> >& dp){
  if(i < 0 || j < 0)
    return INT_MAX;
  if(i == 0 && j == 0)
    return -a[0][0];
  if(dp[i][j] == INT_MAX){
    dp[i][j] = min(abs(points(a,i-1,j,dp)),abs(points(a,i,j-1,dp))) - a[i][j];
  
  }

  return dp[i][j];
}
int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int> > a(m,vector<int>(n));
    for(int i = 0; i < m; i++){
      for(int j = 0;j < n; j++){
        cin >> a[i][j];
      }
    }
    vector<vector<int> > dp(m,vector<int>(n,INT_MAX));
    cout << points(a,m-1,n-1,dp)+1;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cout << dp[i][j] << " ";
      }cout << endl;
    }
    return 0;
}
