#include<bits/stdc++.h>
using namespace std;
int kadane(vector<int>& temp,int n){
  int t_max = INT_MIN,c_max = 0;
  for(int i = 0; i < n; i++){
    t_max = max(t_max,c_max+temp[i]);
    c_max = max(c_max,c_max+temp[i]);
    if(c_max < 0)
      c_max = 0;
  }
  return t_max;
}
int msr(vector<vector<int> >& a,int n,int m){
  int my_max = INT_MIN;
  for(int i = 0; i < n; i++){
    vector<int> temp(n,0);
    for(int j = i; j < m; j++){
      for(int k = 0; k < n; k++){
        temp[k] += a[k][j];
      }
      my_max = max(my_max,kadane(temp,n));
    }
  }
  return my_max;
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > a(n,vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  cout << msr(a,n,m);
  return 0;
}
