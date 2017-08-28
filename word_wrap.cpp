#include<bits/stdc++.h>
using namespace std;
vector<int> path(4,-1);
void print(vector<vector<int> >& dp,int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << dp[i][j] << " ";
    }cout << endl;
  }
}
int ww(vector<int>& v,int n,int len,vector<vector<int> >& dp,vector<int>& best){
  if(n == -1)
    return 0;
  if(best[n] == INT_MAX){
    int total = INT_MAX,temp2;
    for(int i = 0; i <= n; i++){
      int temp = ww(v,i-1,len,dp,best);
      if(dp[i][n] != INT_MAX && total > temp + dp[i][n]){
        total = temp + dp[i][n];
        path[n] = i;
      }
    }
    best[n] = total;
    //path.push_back(temp2);
  }
  return best[n];
}

int main(){
  int n,len;
  cin >> n >> len;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  vector<vector<int> > dp(n,vector<int>(n,INT_MAX));
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      int temp = 0;
      for(int k = j; k <= i; k++)
        temp += v[k];
      if(temp+abs(j-i) <= len)
        dp[i][j] = dp[j][i] = pow(len - temp-abs(j-i),2);
    }
  }
  vector<int> best(n,INT_MAX);
  cout << ww(v,n-1,len,dp,best) << endl;
  print(dp,n,n);
  for(int i = 0; i < path.size(); i++)
    cout << path[i] << endl;
  return 0;
}
