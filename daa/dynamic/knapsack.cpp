#include<bits/stdc++.h>
using namespace std;
int max(int x,int y){return x>y ? x:y;}
void knapsack(int w[],int p[],int n,int W)
{
  int b[n+1][W+1];
  int temp;
  for(int i=0;i<n;i++)b[i][0]=0;
  for(int i=0;i<W;i++)b[0][i]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=W;j++)
    {
      if(w[i] <= W)
      {
        b[i][j] = max(p[i]+b[i-1][W - w[i] ], b[i-1][j] );
      }
      else
      {
        b[i][j] = b[i-1][j];
      }
    }

  }
  int i = n,j = W;
  cout<<"path:"<<endl;
  while(i>0 && j>0)
  {
    if(b[i][j] != b[i-1][j]){
      cout<<i<<endl;
      j = j-w[i];
    }
    i = i-1;
  }

}
int main(int argc, char const *argv[]) {
  int n,W;
  cout<<"enter number of items and capacity of sack"<<endl;
  cin>>n>>W;
  int w[n+1],p[n+1];
  cout<<"enter weight of items"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>w[i];
  }
  cout<<"enter value of item"<<endl;
  for(int i=1;i<=n;i++)
  {
    cin>>p[i];
  }
  knapsack(w,p,n,W);

  return 0;
}
