#include<bits/stdc++.h>
using namespace std;
int edit(string& str1,string& str2,int l1,int l2,vector<vector<int> >& dp){
  if(l2 == -1 || l1 == -1)
    return abs(l2-l1);
  if(dp[l1][l2] == 40){
    if(str1[l1] == str2[l2])
      dp[l1][l2] = edit(str1,str2,l1-1,l2-1,dp);
    else
      dp[l1][l2] = min(1+edit(str1,str2,l1,l2-1,dp),min(1+edit(str1,str2,l1-1,l2-1,dp),1+edit(str1,str2,l1-1,l2,dp)));
  }
  return dp[l1][l2];
}
int main(){
  string str1,str2;
  int l1,l2;
  cin >> str1 >> str2;
  l1 = str1.length();
  l2 = str2.length();
  vector<vector<int> > dp(l1,vector<int>(l2,40));
  cout << edit(str1,str2,l1-1,l2-1,dp);
  return 0;
}
