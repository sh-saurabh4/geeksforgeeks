#include<bits/stdc++.h>
using namespace std;
int lcs(string str1,string str2,int l1,int l2,vector<vector<int> >& dp){
  if(l1 == -1 || l2 == -1)
    return 0;
  if(dp[l1][l2] == -1){
    if(str1[l1] == str2[l2]){
      dp[l1][l2] = lcs(str1,str2,l1-1,l2-1,dp)+1;
    }
    else
    dp[l1][l2] = max(lcs(str1,str2,l1-1,l2,dp),lcs(str1,str2,l1,l2-1,dp));
  }
  return dp[l1][l2];
}
int main(){
    string str1,str2,res = "";
    getline(cin,str1);
    getline(cin,str2);
    int l1,l2;
    l1 = str1.length();
    l2 = str2.length();
    vector<vector<int> > dp(l1,vector<int>(l2,-1));
    lcs(str1,str2,l1-1,l2-1,dp);
    int j = l2-1, i = l1-1;
    while(i >= 0 && j >= 0){
      if(str1[i] == str2[j]){
        res = str1[i] + res;
        i--;j--;
      }
      else if(dp[i-1][j] > dp[i][j-1]){
        i--;
      }
      else
        j--;
    }
    int r = l1 - res.length();
    r += l2 - res.length();
    r += res.length();
    cout << r << endl;
    return 0;
}
