#include<bits/stdc++.h>
using namespace std;
#define INF 99999
int Time =0;
void visit_ap(int source,vector<vector<int> > graph,int vertices,char color[],int pi[],int d[],int low[],int ap[])
{
  color[source] ='g';
  low[source] = d[source] = Time++;
  int child = 0;
  vector<int>::iterator it;
  for( it =graph[source].begin();it != graph[source].end();it++)
  {
    if(color[*it] == 'w')
    {
      child++;
      pi[*it] = source;
      visit_ap(*it,graph,vertices,color,pi,d,low,ap);
      low[source] = min(low[source],low[ *it ]);
      if(pi[source] == -1 && child > 1)
      {
        ap[source] = 1;
      }
      if(pi[source] != -1 && low[ *it ] >= d[source])
      {
        ap[source] = 1;
      }
    }
    else if(pi[source] != *it)
    {
      low[source] = min(low[source],d[ *it ]);
    }
  }
}
void findap(vector<vector<int> >graph,int vertices)
{
  char color[vertices];
  int pi[vertices],d[vertices],low[vertices],ap[vertices];
  for(int i=0;i<vertices;i++)
  {
    color[i] = 'w';
    pi[i] = -1;
    d[i] = 0;
    low[i] = INF;
    ap[i] = 0;
  }
  visit_ap(0,graph,vertices,color,pi,d,low,ap);
  for(int i=0;i<vertices;i++)
  {
    cout<<setw(3)<<ap[i];
  }
  cout<<endl;
}
int main()
{
  int vertices;
  cout<<"enter no of vertices"<<endl;
  cin>>vertices;
  vector<vector <int> >graph(vertices);
  int edges;
  cout<<"enter number of edges"<<endl;
  cin>>edges;
  int u,v;
  cout<<"enter source and destination respectively"<<endl;
  for(int i=0;i<edges;i++)
  {
    cin>>u>>v;
    if(v < vertices)
    {
    graph[u].push_back(v);
    graph[v].push_back(u);
    }
  }
  vector<int>::iterator it;
  for(int i=0;i<vertices;i++)
  {
    cout<<i<<":";
    for(it = graph[i].begin();it != graph[i].end();it++)
    {
      cout<<*it<<"   ";
    }
    cout<<endl;
  }

  findap(graph,vertices);
}
