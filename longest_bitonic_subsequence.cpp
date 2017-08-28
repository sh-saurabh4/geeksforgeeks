#include<bits/stdc++.h>
using namespace std;
int lbs(vector<int>& v,int n){
  vector<int> dpi(n,1);
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(v[i] > v[j])
      dpi[i] = max(dpi[i],dpi[j]+1);
    }
  }
  vector<int> dpd(n,1);
  for(int i = n-2; i >= 0; i--){
    for(int j = n-1; j > i; j--){
      if(v[i] > v[j])
      dpd[i] = max(dpd[i],dpd[j]+1);
    }
  }
  int m = INT_MIN;
  for(int i = 0; i < n; i++){
    m = max(m,dpi[i]+dpd[i]-1);
    //cout<< dpi[i] << "&"<<dpd[i] << " ";
  }
  return m;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      cin >> v[i];
    cout << lbs(v,n);
    return 0;
}
