#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int> >& v,int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << v[i][j]<<" ";
    }
    cout<<endl;
  }
}
int ispal(string& str,int i,int j){
  while(i <= j){
    if(str[i] != str[j])
      return 1;
    i++;
    j--;
  }
  return 0;
}
int pp(string& str,int i,int j,vector<vector<int> >& dp,vector<vector<int> >& pal){
    if(pal[i][j] == -1)
      pal[i][j] = ispal(str,i,j);
    if(pal[i][j] == 0)
      return  0;
    if(dp[i][j] == INT_MAX){
      int temp;
      for(int k = i; k < j; k++){
        temp = pp(str,i,k,dp,pal)+1+pp(str,k+1,j,dp,pal);
        if(dp[i][j] > temp)
          dp[i][j] = temp;
      }
    }
    return dp[i][j];
  }
int main(){
    string str;
    cin >> str;
    int n = str.length();
    vector<vector<int> > dp(n,vector<int>(n,INT_MAX)),pal(n,vector<int>(n,-1));
    cout << pp(str,0,n-1,dp,pal);
    //print(pal,n);
    return 0;
}
