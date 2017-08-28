#include<bits/stdc++.h>
using namespace std;
int ob(vector<int>& keys,vector<int>& freq,int i,int j,vector<vector<int> >& dp,int level){
    if(i == j){
      return dp[i][j] = level*freq[i];
    }
    if(dp[i][j] == INT_MAX){
      for(int k = i; k <= j; k++){
        int temp = level*freq[k];
        if(i < k)
          temp += ob(keys,freq,i,k-1,dp,level+1);
        if(k < j)
          temp += ob(keys,freq,k+1,j,dp,level+1);
        if(temp < dp[i][j])
          dp[i][j] = temp;
      }
    }
    return dp[i][j];
}
int main(){
    clock_t start,end;
    start = clock();
    int n;
    cin >> n;
    vector<int> keys(n),freq(n);
    for(int i = 0; i < n; i++){
      cin >> keys[i] >> freq[i];
    }
    vector<vector<int> > dp(n,vector<int>(n,INT_MAX));
    cout << ob(keys,freq,0,n-1,dp,1)<<endl;
    end = clock();
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC;
    return 0;
}
