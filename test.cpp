#include<bits/stdc++.h>
using namespace std;
void update(int bt[],int n,int index,int delta){
    while(index <= n){
      bt[index] += delta;
      index += (index & (-index));
    }
    return;
}
int findsum(int bt[],int index){
  int sum = 0;
  while(index > 0){
      sum += bt[index];
      index -= (index & (-index));
  }
  return sum;
}
int main(){
    int n;
    cin >> n;
    int arr[n+1],bt[n+1];
    for(int i = 1; i <= n; i++){
      cin >> arr[i];
    }
    memset(bt,0,sizeof(bt));
    for(int i = 1; i <= n; i++){
      update(bt,n,i,arr[i]);
    }
    cout << findsum(bt,7);
    return 0;
}
