#include<bits/stdc++.h>
using namespace std;
void mul(int f[2][2],int m[2][2]){
  int x = f[0][0]*m[0][0]+f[0][1]*m[1][0];
  int y = f[0][0]*m[0][1]+f[0][1]*m[1][1];
  int z = f[1][0]*m[0][0]+f[1][1]*m[0][1];
  int w = f[1][0]*m[0][1]+f[1][1]*m[1][1];
  f[0][0] = x;
  f[0][1] = y;
  f[1][0] = z;
  f[1][1] = w;
}
void mypow(int n,int f[2][2],int m[2][2]){
  if(n == 1)
    return;
  mypow(n/2,f,m);
  mul(f,f);
  if(n % 2 != 0)
    mul(f,m);
}
int fib(int n,int f[][2],int m[][2]){
  if(n == 0 || n == 1)
    return n;
  mypow(n-1,f,m);
  return f[0][0];
}
int main(){
  int n;
  int f[2][2]={{1,1},{1,0}};
  int m[2][2] = {{1,1},{1,0}};
  cin >> n;
  cout << fib(n,f,m);
  //cout <<
  return 0;
}
