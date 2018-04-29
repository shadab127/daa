#include<iostream>
#include<vector>
using namespace std;
vector <int> merging(vector <int> &array1,vector <int> &array2,int size1,int size2)
{
    vector <int> arr1 = array1;
    vector <int> arr2 = array2;

    vector <int> arr3(size1 + size2);
    int i=0,j=0,k=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else
        {
            arr3[k++]=arr2[j++];
        }
    }
    while(i<size1)
    {
        arr3[k++]=arr1[i++];
    }
    while(j<size2)
    {
        arr3[k++]=arr2[j++];
    }
    return arr3;
}
vector <int> mergesort(vector <int> &array,int lower,int higher)
{
    vector <int> arr = array;
    int low = lower;
    int high = higher;
    int mid = (high-low)/2 + low;
    if(low>=high || low == mid)
    {
        vector <int> temp(1);
        temp[0] = arr[mid];
        return temp;
    }
    vector <int> arr1(mid - low);
    for(int i=low,j=0;i<mid;i++)arr1[j++]=arr[i];

    vector <int> arr2(high - mid);
    for(int i=mid,j=0;i<high;i++)arr2[j++]=arr[i];

    vector <int> arr3(high-low);
    arr1 = mergesort(arr,low,mid);
    arr2 = mergesort(arr,mid,high);
    arr3 = merging(arr1,arr2,mid-low,high-mid);
    return arr3;
}
int main()
{
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    arr = mergesort(arr,0,n);
    for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
}
