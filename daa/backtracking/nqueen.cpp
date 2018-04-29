#include<bits/stdc++.h>
using namespace std;
int checkboard(vector<vector <int> > &board,int row,int col,int n)
{
  for(int i=0;i<n;i++)
  {
    if(board[row][i] == 0)
    {
      return 0;
    }
  }
  for(int i=0;i<n;i++)
  {
    if(board[i][col] == 0)
    {
      return 0;
    }
  }
  int c = col - row;
  int x,y;

  for(int i=0;i<n;i++)
  {
    x=i;
    y = x + c;
    if(x > -1 && y > -1 && x < n && y < n)
    {
      if(board[x][y] == 0)
      {
        return 0;
      }
    }

  }
  c = col + row;
  for(int i=0;i<n;i++)
  {
    x=i;
    y= -x + c;
    if(x > -1 && y > -1 && x < n && y < n)
    {
      if(board[x][y] == 0)
      {
        return 0;
      }
    }
  }
  return 1;
}
int nqueen(vector< vector<int> > &board,int n,int &nqueens)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(nqueens == 0)break;
      if(checkboard(board,i,j,n) == 1)
      {
        board[i][j] = 0;
        nqueens--;
        if (nqueen(board,n,nqueens) == 0)
        {
          board[i][j] = -1;
          nqueens++;
        }
      }
    }
    if(nqueens == 0)break;
  }
  if(nqueens)return 0;
  return 1;
}
int main() {
  int boardsize;
  cout<<"enter boardsize"<<endl;
  cin>>boardsize;
  cout<<"enter no of queens you want to place in board"<<endl;
  int nqueens;
  cin>>nqueens;
  vector < vector<int> > board(boardsize,vector<int>(boardsize,-1));
  for(int i=0;i<boardsize;i++)
  {
    cout<<endl;
    for(int j=0;j<boardsize;j++)
    {
      cout<<board[i][j];
    }
  }
  cout<<endl;
  if(nqueen(board,boardsize,nqueens))
  {
  for(int i=0;i<boardsize;i++)
  {
    cout<<endl;
    for(int j=0;j<boardsize;j++)
    {
      cout<<setw(3)<<board[i][j];
    }
  }
  cout<<endl;
  }
  else
  {
    cout<<"not possible"<<endl;
  }
  return 0;
}
