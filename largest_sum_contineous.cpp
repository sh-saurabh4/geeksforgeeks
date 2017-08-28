#include<bits/stdc++.h>
using namespace std;
int ls(vector<int>& v,int n){
  if(n == 0)
    return v[0];
  int maxc = v[0],maxt = v[0];
  int start = 0,end = 0,s=0;
  for(int i = 1; i <= n; i++){
    maxc = max(maxc+v[i],v[i]);
    maxt = max(maxc,maxt);  
  }
  //cout << start << " to "<< end << endl;
  return maxt;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      cin >> v[i];
    cout << ls(v,n-1);
    return 0;
}
