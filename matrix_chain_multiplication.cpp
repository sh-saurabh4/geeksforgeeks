#include<bits/stdc++.h>
using namespace std;
int mcm(vector<int>& v,int i, int j,vector<vector<int> >& dp){
  if(i == j)
    return 0;
  if(dp[i][j] == -1){
    int temp,min = INT_MAX;
    //cout<<i<<j;
    //cin>>temp;
    for(int k = i; k < j; k++){
      temp = mcm(v,i,k,dp)+mcm(v,k+1,j,dp)+v[i-1]*v[k]*v[j];
      if(temp < min)
        min = temp;
    }
       dp[i][j] = min;
   }
  return dp[i][j];
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      cin >> v[i];
    vector<vector<int> > dp(n,vector<int>(n,-1));
    cout << mcm(v,1,n-1,dp);
    return 0;
}
