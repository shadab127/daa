#include<bits/stdc++.h>
using namespace std;
bool inbetween(int x,int y,int z)
{
    if(x<y && x>z)return true;
    if(x>y && x<z)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int n;
    scanf("%d",&n);
    int x,y;
    int sum=0;
    while(n--)
    {

    cin>>x>>y;
    if(inbetween(x,x1,x2))
    {
        if(inbetween(y,y1,y2))sum++;
    }
    }
    printf("%d\n",sum);
    }
}
