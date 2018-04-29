#include<bits/stdc++.h>
using namespace std;
int *arr = new int[100000001];
long long int fun(long long int n)
{
  if(arr[n] > 0)return arr[n];
  long long int n1 = n/2;
  long long int n2 = n/3;
  long long int n3 = n/4;
  if(n1 > 2)
  {
    n1 = fun(n1);
  }
  if(n2 > 3)
  {
    n2 = fun(n2);
  }
  if(n3 > 4)
  {
    n3 = fun(n3);
  }
  if( (n1+n2+n3) > n)
  {
    if(n1+n2+n3 < 100000001)arr[n] = n1+n2+n3;

    return (n1+n2+n3);
  }
  else
  {  if(n1+n2+n3 < 100000001)arr[n] = n;

  return n;
  }
}
int main()
{
  int i = 100000001;
  while(i--)
  {
    arr[i] = -1;
  }
  long long n;
  while(scanf("%lld",&n)>0){
    printf("%lld\n",fun(n));
  }
  return 0;

}
