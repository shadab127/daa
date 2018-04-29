#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> ipair;
class graph{
  int v;
  list <pair<int,int> > *adj;
public:
  graph(int v);
  void addedge(int u,int v, int w);
  void dijkastra(int s);
};
graph::graph(int v)
{
  this->v = v;
  adj = new list<ipair> [v];
}
void graph:: addedge(int u,int v,int w){
  adj[u].push_back(make_pair(v,w));
  adj[v].push_back(make_pair(u,w));
}
void graph::dijkastra(int s){
  priority_queue< ipair, vector<ipair>,greater<ipair> > pq;
  vector<int> dist(v,INF);
  pq.push(make_pair(0,s));
  dist[s] = 0;
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    list<pair<int,int> >::iterator i;
    for(i = adj[u].begin();i != adj[u].end();++i){
      int v = (*i).first;
      int weight = (*i).second;
      if(dist[v] > dist[u] + weight){
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v],v));
      }

    }

  }

        for(int i =0 ;i<v;i++)
        {
          cout<<"  vertex :"<<i<<"  distance :"<<dist[i]<<endl;
        }
}


int main(){
  int v;
  cout<<"enter no. of vertices"<<endl;
  cin>>v;
  graph g(v);
  int x,y,w;
  cout<<"enter no edges"<<endl;
  int e;
  cin>>e;
  for(int i=0;i<e;i++)
  {
    cout<<"enter src,dest, weight"<<endl;
    cin>>x>>y>>w;
    g.addedge(x,y,w);
  }
  g.dijkastra(0);
  return 0;

}
