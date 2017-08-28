#include<bits/stdc++.h>
using namespace std;
int m,n;
int row[] = {-1,-1,-1,0,0,0,1,1,1};
int col[] = {-1,0,1,-1,0,1,-1,0,1};
int mylen(vector<vector<char> >& a,int i,int j,vector<vector<int> >& dp){
  if(dp[i][j] == -1){
    dp[i][j] = 1;
    for(int k = 0; k < 9; k++){
      int x = i+row[k];
      int y = j+col[k];
      if(x < m && x >= 0 && y < n && y >= 0 && a[x][y]-a[i][j] == 1){
        dp[i][j] += mylen(a,x,y,dp);
      }
    }
  }
  return dp[i][j];
}
int main(){
  //int m,n;
  cin >> m >> n;
  vector<vector<char> > a(m,vector<char>(n));
  for(int i = 0; i < m; i++){
    for(int j = 0; j  < n; j++){
      cin >> a[i][j];
    }
  }//cout << a[0][0];
  vector<vector<int > > dp(m,vector<int>(n,-1));
  cout << mylen(a,0,0,dp);
  return 0;
}
