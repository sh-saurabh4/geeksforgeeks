#include<bits/stdc++.h>
using namespace std;
struct edge{
  int u;
  int v;
  int w;
  edge(){u = 0; v = 0; w = 0;}
  edge(int x,int y,int z){u=x;v=y;w=z;}
};
void print(vector<int>& dist,int v){
  for(int i = 0; i < v; i++){
    cout << dist[i] << " ";
  }cout << endl;
}
void relax(edge *temp,vector<int>& dist){
  cout << temp->u << temp->v << temp->w << endl;
  if(dist[temp->u]+temp->w < dist[temp->v]){
    dist[temp->v] = dist[temp->u]+temp->w;
  }
}
void bell(vector<edge>& graph,vector<int>& dist,int v,int e){
  for(int i = 0; i < v; i++){
    for(int j = 0; j < e; j++){
      relax(&graph[j],dist);
      print(dist,v);
    }
  }
}
int main(){
    int v,e;
    cin >> v >> e;
    vector<edge> graph;
    for(int i = 0; i < e; i++){
      int x,y,z;
      cin >> x >> y >> z;
      graph.push_back(edge(x,y,z));
    }
    vector<int> dist(v,INT_MAX);
    dist[0] = 0;
    bell(graph,dist,v,e);
    return 0;
}
