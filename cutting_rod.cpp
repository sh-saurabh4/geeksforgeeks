#include<bits/stdc++.h>
using namespace std;
int cr(vector<int>& len,vector<int>& pri,int l,int n,vector<int>& dp){
  if(l == 0)
    return 0;
  if(dp[l] == -1){
    int max = INT_MIN,temp;
    for(int i = 0; i < n; i++){
      if(l-len[i] >= 0){
        temp = cr(len,pri,l-len[i],n,dp)+pri[i];
        if(max < temp)
          max = temp;
        }
    }
    dp[l] = max;
  }
  return dp[l];
}
int main(){
    int l,n;
    cin >> l >> n;
    vector<int> len(n),pri(n);
    for(int i = 0; i < n; i++)
      cin >> len[i];
    for(int i = 0; i < n; i++)
      cin >> pri[i];
    vector<int> dp(l+1,-1);
    cout << cr(len,pri,l,n,dp);
    //for(int i = 0; i < n; i++){
      //cout << dp[i] << " ";
    }
    return 0;

}
