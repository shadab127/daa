#include<bits/stdc++.h>
using namespace std;
int chessboard[8][8];
int move_ = 0;


bool allsquarevisited()
{

  cout<<endl;
    for(int i=0;i<8;i++)
    {
      cout<<endl;
      for(int j=0;j<8;j++)
      {
        printf("%3d    ",chessboard[i][j]);
      }
    }

    cout<<endl;

  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      if(chessboard[i][j] < 0)
      {
        return false;
      }
    }
  }
  return true;
}


bool knight_tour(int x,int y)
{

  cout<<"  "<<x<<"  "<<y<<endl;
  if(allsquarevisited())return true;
  else
  {
    chessboard[x][y] = move_;
    move_++;
    int mov[2][8];
    mov[0][0] = x+2;mov[0][1] = y+1;
    mov[1][0] = x+1;mov[1][1] = y+2;
    mov[2][0] = x-1;mov[2][1] = y+2;
    mov[3][0] = x-2;mov[3][1] = y+1;
    mov[4][0] = x-2;mov[4][1] = y-1;
    mov[5][0] = x-1;mov[5][1] = y-2;
    mov[6][0] = x+1;mov[6][1] = y-2;
    mov[7][0] = x+2;mov[7][1] = y-1;
    for(int i=0;i<8;i++)
    {
      if(mov[i][0] >= 0 && mov[i][0] < 8 && mov[i][1] >= 0 && mov[i][1] < 8)
      {
      if(chessboard[ mov[i][0] ][ mov[i][1] ] < 0)
      {
       if(!knight_tour(mov[i][0],mov[i][1]))
       {
          move_--;
          chessboard[ mov[i][0] ][ mov[i][1] ] = -1;
          //return false;
       }
     }
   }
  }
  cout<<endl<<move_<<"    ****"<<endl;
  if(allsquarevisited())return true;
  return false;
  }

}

int main(int argc, char const *argv[]) {
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      chessboard[i][j] = -1;
    }
  }
  cout<<endl;
    for(int i=0;i<8;i++)
    {
      cout<<endl;
      for(int j=0;j<8;j++)
      {
        cout<<chessboard[i][j];
      }
    }
  int x,y;
  cout<<"enter initial position of knight on board"<<endl;
  cin>>x>>y;
  if(knight_tour(x,y))
  {
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
        cout<<chessboard[i][j];
      }
    }
  }
  else
  {
    cout<<"not possible";
  }


  return 0;
}
