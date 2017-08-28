#include<bits/stdc++.h>
using namespace std;
int ms(vector<vector<int> >& matrix,int m,int n){
  if(m <= 0 || n <= 0)
    return 0;
  int sum[m][n];
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      sum[i][j] = matrix[i][j];
    }
  }
  int max = 0;
  for(int i = 1; i < m; i++){
    for(int j = 1; j < n; j++){
      if(sum[i][j] != 0){
        sum[i][j] = min(sum[i-1][j],min(sum[i-1][j-1],sum[i][j-1]))+1;
      }
      if(max < sum[i][j])
        max = sum[i][j];
      cout << sum[i][j] <<" ";
    }cout << endl;
  }
  return max;
}
int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int> > matrix(m,vector<int>(n));
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cin >> matrix[i][j];
      }
    }
    cout << ms(matrix,m,n);
    return 0;
}
