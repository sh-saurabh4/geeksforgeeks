#include<bits/stdc++.h>
using namespace std;
int fun(int n){
  if(n == 1)
    return 1;
  if(n == 2)
    return 2;
  return fun(n-1)+fun(n-2);
}
int main(){
  int n;
  cin >> n;
  cout << fun(n);
  return 0;

}
