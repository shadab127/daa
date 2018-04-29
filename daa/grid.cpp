#include<bits/stdc++.h>
using namespace std;
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define INF 999999
struct pair1
{
    int x;int y;
};
int main()
{
 int n,m,q;
 scanf("%d%d%d",&n,&m,&q);
 string grid[n][m];
 string s[m];
 for(int i=0;i<n;i++)
 {
     scanf("%s",s);
     for(int j=0;j<m;j++)
     {
         grid[i][j] = s[j];
     }
 }
 pair1 source;
 cin>> source.x >> source.y;
 int d1,d2;
 int dist[n][m];
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         dist[i][j] = INF;
     }
 }
 int visited[n][m];

 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         if(grid[i][j] == "*")visited[i][j] = 1;
         else
            visited[i][j] = 0;
     }
 }

 queue <pair1> myqueue ;
 myqueue.push(source);
 dist[source.x][source.y] = 0;
 visited[source.x][source.y] = 1;
 while(!myqueue.empty())
 {
     pair1 p1;
     p1 = myqueue.front();
     pair1 p2,p3,p4,p5;
     p2.x = p1.x -1;p2.y = p1.y;
     p3.x = p1.x +1;p3.y = p1.y;
     p4.x = p1.x   ;p4.y = p1.y-1;
     p5.x = p1.x   ;p5.y = p1.y+1;
     if(p2.x >= 0)
     {
         if(!visited[p2.x][p2.y])
         {
             if(dist[p1.x][p1.y] + 1 < dist[p2.x][p2.y])
             {
                 dist[p2.x][p2.y] = dist[p1.x][p1.y] + 1;
             }
             visited[p2.x][p2.y] = 1;
             myqueue.push(p2);
         }

     }
     if(p3.x<=n-1)
     {
         if(!visited[p3.x][p3.y])
         {
             if(dist[p1.x][p1.y] + 1 < dist[p3.x][p3.y])
             {
                 dist[p3.x][p3.y] = dist[p1.x][p1.y] + 1;
             }
             visited[p3.x][p3.y] = 1;
             myqueue.push(p3);
         }

     }
     if(p4.y >=0)
     {

         if(!visited[p4.x][p4.y])
         {
             if(dist[p1.x][p1.y] + 1 < dist[p4.x][p4.y])
             {
                 dist[p4.x][p4.y] = dist[p1.x][p1.y] + 1;
             }
             visited[p4.x][p4.y] = 1;
             myqueue.push(p4);
         }

     }
     if(p5.y <= m-1)
     {

         if(!visited[p5.x][p5.y])
         {
             if(dist[p1.x][p1.y] + 1 < dist[p5.x][p5.y])
             {
                 dist[p5.x][p5.y] = dist[p1.x][p1.y] + 1;
             }
             visited[p5.x][p5.y] = 1;
             myqueue.push(p5);
         }

     }
     myqueue.pop();
 }

 while(q--)
 {
    scan(d1);
    scan(d2);
    if(dist[d1-1][d2-1] == INF)print(-1);
    else
    {
        print(dist[d1-1][d2-1]);
    }
 }
}
