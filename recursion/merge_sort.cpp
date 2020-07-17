#include<bits/stdc++.h>
#define ll long long
using namespace std;
void merge(int *arr,int s,int e)
{
	int a[100];
	int mid=(s+e)/2;
	int i=s,j=s,k=mid+1;
	while(i<=mid && k<=e)
	{
		if(arr[i]<arr[k])
		{
			a[j++]=arr[i++];
		}
		else
		{
			a[j++]=arr[k++];
		}
	}
	while(i<=mid)
	{
		a[j++]=arr[i++];
	}
	while(k<=e)
	{
		a[j++]=arr[k++];
	}
	for(int i=s;i<=e;i++)
	{
		arr[i]=a[i];
	}
}
void merge_sort(int *arr,int s,int e)
{
	if(s>=e)
	return;
	int mid=(s+e)/2;
	merge_sort(arr,s,mid);
	merge_sort(arr,mid+1,e);
	merge(arr,s,e);
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
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}