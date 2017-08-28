#include<bits/stdc++.h>
using namespace std;
struct node{
  int h;
  int b;
  int l;
  int ar;
};
bool comp(node x,node y){
  return x.ar  > y.ar;
}
int bs(vector<node>& v,int n,vector<int>& dp){
  if(n == -1)
    return 0;
  if(dp[n] == -1){
    int max = v[n].h;
    for(int i = 0; i < n; i++){
      int temp  = bs(v,i,dp);
      if(v[i].b > v[n].b && v[i].l > v[n].l && max < temp + v[n].h)
        max = temp + v[n].h;
    }
    dp[n] = max;
  }
  return dp[n];
}
int main(){
    int n;
    cin >> n;
    vector<node> v(n*3);
    for(int i = 0; i < n*3; i+=3){
      int x,y,z;
      cin >> x >> y >> z;
      v[i].h = x;v[i].b = y;v[i].l = z;v[i].ar=y*z;
      v[i+1].h = y; v[i+1].b = x;v[i+1].l = z;v[i+1].ar=x*z;
      v[i+2].h = z; v[i+2].b = x;v[i+2].l = y;v[i+2].ar=x*y;
    }
    sort(v.begin(),v.end(),comp);
    vector<int> dp(n*3,-1);
    cout << bs(v,n*3-1,dp) << endl;
    //for(int i = 0; i < n*3; i++){
    //  cout << v[i].h <<" "<< v[i].b <<" "<< v[i].l <<" "<< v[i].ar << endl;
    //}
    return 0;
}
