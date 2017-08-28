#include<bits/stdc++.h>
using namespace std;
struct node{
  int a;
  int b;
};
int bb(vector<node>& v,int n,vector<int>& dp){
  if(n == 0){
    if(v[0].a == v[0].b)
      return 1;
    else
      return 0;
  }
  if(dp[n] == -1){
    int max = 0;
    for(int i = 0; i < n; i++){
      int temp = bb(v,i,dp);
      if(v[i].b == v[n].a || v[i].a == v[n].b || v[n].a == v[n].b){
        if(max < temp + 1)
          max = temp + 1;
      }

    }
    dp[n] = max;
  }
  return dp[n];
}

int main(){
  int n;
  cin >> n;
  vector<node> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].a >> v[i].b;
  }
  vector<int> dp(n,-1);
  cout << bb(v,n-1,dp);
  return 0;
}
