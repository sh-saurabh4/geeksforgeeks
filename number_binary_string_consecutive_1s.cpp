#include<bits/stdc++.h>
using namespace std;
int find(vector<int>& a,vector<int>& b,int n){
  a[0] = b[0] = 1;
  for(int i = 1; i <= n; i++){
    a[i] = a[i-1] + b[i-1];
    b[i] = a[i-1];
  }
  return a[n]+b[n];
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  cout << find(a,b,n-1);
  return 0;
}
