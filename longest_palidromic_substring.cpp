#include<bits/stdc++.h>
using namespace std;
int lps(string& str,int i,int j,vector<vector<int> >& dp){
  if(i > j)
    return 1;
  if(i == j)
    return dp[i][j] = 1;
  if(dp[i][j] == -1){
    lps(str,i+1,j,dp);
    lps(str,i,j-1,dp);
    if(lps(str,i+1,j-1,dp) == 1 && str[i] == str[j])
      dp[i][j] = 1;
    else
      dp[i][j] = 0;
  }
  return dp[i][j];
}
int main(){
  string str;
  cin >> str;
  int l = str.length();
  vector<vector<int> > dp(l,vector<int>(l,-1));
  lps(str,0,l-1,dp);
  int m = dp[0][0];int start = 0,end = 0;
  for(int i = 0; i < l; i++){
    for(int j = i; j < l; j++){
      if(dp[i][j] == 1){
        m = max(m,j-i+1);
        if(m == j-i+1){
          start = i;
          end = j;
        }
      }
    }
  }
  cout << m << " "<<str.substr(start,end-start+1);
  return 0;
}
