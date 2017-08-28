#include<bits/stdc++.h>
using namespace std;
int ispal(string& str,int i,int j){
  while(i <= j){//cout<<str[i]<<"&"<<str[j]<<" ";
    if(str[i] != str[j])
      return 0;
    i++;
    j--;
  }
  return 1;
}

int pp(string& str,int n,vector<int>& dp,vector<vector<int> >& pal ){
  //if(n == 0)
  //  return 0;
  if(pal[0][n] == -1){
    pal[0][n] = ispal(str,0,n);
  }
  if(pal[0][n] == 1)
    return 0;
  if(dp[n] == INT_MAX){
    int temp;
    for(int i = 0; i < n; i++){
      temp = pp(str,i,dp,pal);
      if(pal[i+1][n] == -1){//cout<<"helo";
        pal[i+1][n] = ispal(str,i+1,n);//cout<<pal[i+1][n];
      }
      if(pal[i+1][n] == 1 && temp+1 < dp[n])
        dp[n] = temp+1;
    }
  }
  return dp[n];
}
int main(){
  string str;
  cin >> str;
  int l = str.length();
  vector<int> dp(l,INT_MAX);
  vector<vector<int> > pal(l,vector<int>(l,-1));
  cout<<pp(str,l-1,dp,pal);
  /*for(int i = 0; i < l; i++){
    for(int j = 0; j < l; j++){
      cout<<pal[i][j]<<" ";
    }cout<<endl;
  }
  cout << ispal(str,1,7);
  */return 0;
}
