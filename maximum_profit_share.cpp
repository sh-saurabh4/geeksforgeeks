#include<bits/stdc++.h>
using namespace std;
int find(vector<int>& a,int n){
  vector<int> profit(n,0);
  int max_sofar = a[n-1];
  for(int i = n-2; i >= 0; i--){
      max_sofar = max(max_sofar,a[i]);
      profit[i] = max(profit[i+1],max_sofar-a[i]);
  }
  int min_sofar = a[0];
  for(int i = 1; i < n; i++){
    min_sofar = min(min_sofar,a[i]);
    profit[i] = max(profit[i-1],a[i]-min_sofar+profit[i]);
  }
  return profit[n-1];
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    cout << find(a,n);
    return 0;
}
