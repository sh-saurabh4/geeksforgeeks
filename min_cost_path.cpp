#include<bits/stdc++.h>
using namespace std;
int cost(vector<vector<int> >& v,int n, int m,vector<vector<int> >& dp){
  if(n == 0 && m == 0)
    return v[0][0];
  if(dp[n][m] == -1){
      int x,y,z;
      x=y=z=INT_MAX;
      if(n-1 >= 0)
        x = cost(v,n-1,m,dp);
      if(m-1 >= 0)
        y = cost(v,n,m-1,dp);
      if(n-1>=0 && m-1>=0)
        z = cost(v,n-1,m-1,dp);
      dp[n][m] = v[n][m] + min(x,min(y,z));
  }
  return dp[n][m];
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > v(n,vector<int>(m)),dp(n,vector<int>(m,-1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    cin >> n >> m;
    cout << cost(v,n,m,dp);
    return 0;
}
