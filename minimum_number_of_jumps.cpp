#include<bits/stdc++.h>
using namespace std;
int mjumps(vector<int>& v,int n,vector<int>& dp){
  if(n == 0)
    return dp[0] = 0;
  if(dp[n] == -1){
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
      int temp = mjumps(v,i,dp);
      if(v[i] >= n-i && temp+1 < min)
        min = temp + 1;//cout<<"hello";
    }
    dp[n] = min;
  }
  return dp[n];
}
int main(){
  int n;
  cin >> n;
  int data;
  vector<int> v;
  for(int i = 0; i < n; i++){
    cin >> data;
    v.push_back(data);
  }
  vector<int> dp(n,-1);
  cout << mjumps(v,n-1,dp);
  //for(int i = 0; i < n; i++)
  //  cout << dp[i] <<" ";
  cout<<endl;
  return 0;
}
