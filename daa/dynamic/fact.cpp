#include<bits/stdc++.h>
using namespace std;
int INT = 1000000007;
long long int fact(long long int n,long long int arr[])
{
    if(arr[n]>0)return(arr[n]);
    else
    {
        arr[n] = ((n%INT) * (fact(n-1,arr) % INT)) % INT;
    }
    return arr[n];
}
int main()
{
    long long int n,t;
    long long int arr[100001];
    int i=100001;
    while(i--)arr[i] = -1;
    cin>>t;
    arr[0] = arr[1] = 1;
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",fact(n,arr));
    }
}
