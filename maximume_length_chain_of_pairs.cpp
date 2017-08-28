#include<bits/stdc++.h>
using namespace std;
struct mpair
{
  int a;
  int b;
  //mpair() : a(0),b(0){}
  //mpair(int x,int y) : a(x),b(y){}
};
int mlc(vector<mpair>& v,int n,vector<int>& dp){
  if(n == 0)
    return 1;
  if(dp[n] == INT_MIN){
    int max = 1;
    for(int i = 0; i < n; i++){
      int temp = mlc(v,i,dp);//cout<<temp;
      if(v[i].b < v[n].a && temp + 1 > max){
        max = temp + 1;//cout<<"hello";
      }
    }
    dp[n] = max;
  }
  return dp[n];
}
int main(){
  int n;
  cin >> n;
  vector<mpair> v(n);
  //v.push_back(mpair());
  for(int i = 0; i < n; i++)
   cin >> v[i].a >> v[i].b;
  vector<int> dp(n,INT_MIN);
  cout << mlc(v,n-1,dp);
  for(int i = 0; i < n; i++)
    cout << dp[i]<<" ";
  return 0;

}
