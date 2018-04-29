#include<bits/stdc++.h>
using namespace std;

long dp[1000000]={0};

long func(long long n)
{
    if(n<=2)
    return n;
    if(n<1000000&&dp[n]!=0)
    return dp[n];
    long long k=func(n/2)+func(n/3)+func(n/4);
    if(n<1000000)
    dp[n]=max(n,k);
    return max(n,k);
}

int main()
{
    long long n;
    while(scanf("%lld",&n)>0){
    cout<<func(n)<<"\n";
    }
    return 0;
}
