#include<bits/stdc++.h>
using namespace std;
int ways(int n){
  int a[n+1];
  int b[n+1];
  a[1] = 1;
  b[1] = 1;
  for(int i = 2; i <= n; i++){
    a[i] = a[i-1]+b[i-1];
    b[i] = a[i-1];
  }
  int t = a[n]+b[n];
  return pow(t,2);
}
int main(){
    int n;
    cin >> n;
    cout << ways(n);
    return 0;
}
