#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int> >& v,int n,int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << v[i][j]<<" ";
    }
    cout<<endl;
  }
}
int partition(vector<int>& set,int n,int sum,vector<vector<int> >& dp){
  if(sum == 0)
    return 1;
  if( n == -1){
    if(sum == 0)
      return 1;
    else
      return 0;
  }
  if(dp[n][sum] == -1){//cout << "hello";
    int x = partition(set,n-1,sum,dp);
    int y = partition(set,n-1,sum-set[n],dp);
    dp[n][sum] = x || y;
  }
  return dp[n][sum];
}
int main(){
  vector<int> set;
  int n,data,total=0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> data;
    set.push_back(data);
    total+=data;
  }//cout<<total;
  if(total%2 == 1)
    cout<<0<<endl;
  else{
    int sum = total/2;
    vector<vector<int> > dp(n,vector<int>(sum+1,-1));
    cout << partition(set,n-1,sum,dp);
  //  print(dp,n,sum+1);
  }
  return 0;
}
