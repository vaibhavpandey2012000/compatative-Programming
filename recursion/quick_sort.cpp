#include<bits/stdc++.h>
#define ll long long
using namespace std;
int partition(int *arr,int s,int e)
{
	int ele=arr[e];
	int i=s-1,j=s;
	for( j=s;j<e;j++)
	{
		if(arr[j]<=ele)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[e],arr[i+1]);
	return i+1;
}
void quick_sort(int *arr,int s,int e)
{
	if(s>=e)
	return;
	int piv=partition(arr,s,e);
	quick_sort(arr,s,piv-1);
	quick_sort(arr,piv+1,e);
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	quick_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}