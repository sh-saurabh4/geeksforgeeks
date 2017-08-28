#include<bits/stdc++.h>
using namespace std;
struct point{
  int x;
  int y;
};
double dist(vector<point>& a,int i,int j){
  return sqrt(pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2));
}
double cost(vector<point>& a, int i, int j,int k){
  return dist(a,i,j)+dist(a,j,k)+dist(a,i,k);
}
double tp(vector<point>& a,int i,int j,vector<vector<double> >& dp){
  if(j < i+2)
    return 0;
  if(dp[i][j] == -1){
    dp[i][j] = INT_MAX;
    for(int k = i+1; k < j; k++){
      double temp = tp(a,i,k,dp)+tp(a,k,j,dp)+cost(a,i,j,k);
      if(dp[i][j]  > temp)
        dp[i][j] = temp;
    }
  }
  return dp[i][j];
}
int main(){
    int n;
    cin >> n;
    vector<point> a(n);
    for(int i = 0; i < n; i++){
      cin >> a[i].x >> a[i].y;
    }
    vector<vector<double> > dp(n,vector<double>(n,-1));
    cout << tp(a,0,n-1,dp);
    return 0;
}
