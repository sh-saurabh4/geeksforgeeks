#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int> >& dist,int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(dist[i][j] == INT_MAX)
        cout<<"INF ";
      else
        cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
}
void fw(vector<vector<int> >& dist,int n){
  print(dist,n);cout<<endl;
  for(int k = 0; k < n; k++){
      for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
            if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k]+dist[k][j])
              dist[i][j] = dist[i][k]+dist[k][j];
          }
      }print(dist,n);cout<<endl;
  }
  print(dist,n);
}
int main(){
    int n;
    cin >> n;
    vector<vector<int> > dist(n,vector<int>(n));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> dist[i][j];
        if( dist[i][j] == -1){
          dist[i][j] = INT_MAX;//cout<<"hello";
        }
      }
    }
    fw(dist,n);
    return 0;
}
