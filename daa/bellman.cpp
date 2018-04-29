#include<bits/stdc++.h>
using namespace std;
#define INF 9999999
struct edge{
  int src;
  int dest;
  int weight;
};
int bellman(edge edge[],int source,int n,int e,int dist[])
{
  dist[source] = 0;

  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<e;j++)
    {
      int u = edge[j].src;
      int v = edge[j].dest;
      int w = edge[j].weight;
      if(dist[u] != INF && dist[v] > dist[u]+w)
      {
        dist[v]=dist[u]+w;

      }
    }
  }
    for(int j=0;j<e;j++)
    {
      int u = edge[j].src;
      int v = edge[j].dest;
      int w = edge[j].weight;
      if(dist[u] != INF && dist[v] > dist[u]+w)
      {
        return 0;

      }
    }
    return 1;
}
int main()
{
  int n,e;
  cout<<"enter no. of nodes and edges in graph"<<endl;
  cin>>n>>e;
  edge edge[e];
  cout<<"enter sorce,destination and edge weight"<<endl;
  for(int i =0;i<e;i++)
  {
    cin>>edge[i].src>>edge[i].dest>>edge[i].weight;
  }
  int dist[n];
  for(int i=0;i<n;i++)dist[i]=INF;

  if(bellman(edge,0,n,e,dist))
  {
    for(int i=0;i<n;i++)cout<<"vertex :"<<i<<" distance:"<<dist[i]<<endl;
  }
  else
  {
    cout<<"graph contains negative cycle"<<endl;
  }
}
