#include<bits/stdc++.h>
using namespace std;
class graph{
public:
  int source;
  int destination;
  int weight;
};
bool compare(graph edge1,graph edge2){
  if(edge1.weight < edge2.weight){
    return true;
  }
  else{
    return false;
  }
}
int findparent(int vertex,int* parent){
  if(parent[vertex] == vertex){
    return vertex;
  }
  return findparent(parent[vertex],parent);

}
void kruskal(graph *input,graph *output,int n,int e){

  sort(input,input + e,compare);
  int *parent = new int[n];
  for(int i=0;i<n;i++)parent[i] = i;
  int count =0;
  int i =0;
  while(count != n-1){
  int sourceparent = findparent(input[i].source,parent);
  int destinationparent = findparent(input[i].destination,parent);
  if(sourceparent != destinationparent){
    output[count] = input[i];
    parent[sourceparent] = destinationparent;
    count++;
  }
  i++;
  }
}
int main(int argc, char const *argv[]) {
  int n,e;
  cin>>n>>e;
  graph *input = new graph[e];
  graph *output = new graph[n-1];

  int u,v,w;
  for(int i=0;i<e;i++){
    cin>>u>>v>>w;
    input[i].source = u;
    input[i].destination = v;
    input[i].weight = w;
  }
  kruskal(input,output,n,e);
  for(int i=0;i<n-1;i++)
  {
    cout<<output[i].source<<"   "<<output[i].destination<<"   "<<output[i].weight<<endl;
  }
  return 0;
}
