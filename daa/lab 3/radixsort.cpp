#include<bits/stdc++.h>
using namespace std;
void countsort(vector<int>&arr,int size,int exp);

int maximum(vector<int> &arr,int size)
{
    int max = arr[0];
    for(int i=0;i<size;i++)
    {
        if(max<arr[i])max=arr[i];
    }
    return max;
}
void radixsort(vector<int> &arr,int size)
{
    int max = maximum(arr,size);

    for(int i=1;i<=max;i= i*10)
    {
        countsort(arr,size,i);
    }
}
void countsort(vector<int>&arr,int size,int exp)
{
    vector<int>temp(10);
    for(int i=0;i<10;i++)
    {
        temp[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        temp[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        temp[i]+=temp[i-1];
    }
    vector<int>sortedarr(size);
    for(int i=0;i<size;i++)
    {
        sortedarr[temp[(arr[i]/exp)%10]-1] = arr[i];
        temp[(arr[i]/exp)%10]--;
    }
    arr = sortedarr;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    radixsort(arr,n);
    for(int i=0;i<n;i++)cout<<"   "<<arr[i];

}
