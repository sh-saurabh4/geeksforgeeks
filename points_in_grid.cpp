#include<bits/stdc++.h>
using namespace std;
int b[] = {-1,0,1};
int row,col;
int path[6];
int points(vector<vector<int> >& a,int n,int i,int j,vector<vector<vector<int> > >& dp){
  if(n == row - 1 && i == 0 && j == col-1)
    return a[row-1][0]+a[row-1][col-1];
  if(n == row - 1)
    return INT_MIN;
  if(dp[n][i][j] == -1){
    dp[n][i][j] = INT_MIN;
    for(int k = 0; k < 3;k++){
      for(int l = 0; l < 3; l++){
        int x = i + b[k];
        int y = j + b[l];//cout<<x<<" "<<y<<endl;
        if(x >= 0 && x < col && y >= 0 && y < col && i == j){
          dp[n][i][j] = max(points(a,n+1,x,y,dp)+a[n][i],dp[n][i][j]);
          //if(dp[n][i][j] == points(a,n+1,x,y,dp)+a[n][i] && n == 3)
           //cout << "a(" << n <<", "<< i <<", "<< j <<","<<dp[n][i][j]<<") "<<endl;
        }
        else if(x >= 0 && x < col && y >= 0 && y < col){
          dp[n][i][j] = max(points(a,n+1,x,y,dp)+a[n][i]+a[n][j],dp[n][i][j]);
          //if(dp[n][i][j] == points(a,n+1,x,y,dp)+a[n][i]+a[n][j] && n == 3)
            //cout << "a(" << n <<", "<< i <<", "<< j <<","<<dp[n][i][j]<<") "<<endl;
        }
      }
    }

  }
  return dp[n][i][j];
}
int main(){
    int m,n;
    cin >> m >> n;
    row = m;
    col = n;
    vector<vector<int> > a(m,vector<int>(n));
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cin >> a[i][j];
        //cout << a[i][j] <<" ";
      }//cout << endl;
    }
    vector<vector<vector<int> > > dp(m,vector<vector<int> >(n,vector<int>(n,-1)));
    cout << points(a,0,0,n-1,dp);
    /*for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
          cout << dp[i][j][k] << " ";
        }cout << endl;
      }cout<<endl;
    }*/
    //cout << a[row-1][0] + a[row-1][col-1];
    return 0;
}
