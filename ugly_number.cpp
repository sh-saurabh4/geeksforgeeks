#include<bits/stdc++.h>
using namespace std;
int ug(vector<int>& v,int n){
  v[0] = 1;
  int i,j,k;
  i = j = k = 0;
  int next2 = v[i]*2;
  int next3 = v[j]*3;
  int next5 = v[k]*5;
  for(int l = 1; l < n; l++){
    v[l] = min(next2,min(next3,next5));
    if(v[l] == next2){
      i++;
      next2 = v[i]*2;
    }
    if(v[l] == next3){
      j++;
      next3 = v[j]*3;
    }
    if(v[l] == next5){
      k++;
      next5 = v[k]*5;
    }
  }
  return v[n-1];
}
int main(){
  int n;
  cin >> n;
  vector<int> v(n+1);
  cout << ug(v,n);
  //for(int i = 0; i < n; i++)
  //  cout << v[i] << " ";
  cout << endl;
  return 0;
}
