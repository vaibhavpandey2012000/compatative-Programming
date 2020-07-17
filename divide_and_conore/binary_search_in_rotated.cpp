#include<bits/stdc++.h>
using namespace std;
/*
int binary_search(int arr[],int s,int e,int key)
{
	if(s>e)
		return -1;
	int mid=(s+e)/2;
	if(arr[mid]==key)
		return mid;
	if(arr[s]<=arr[mid])
	{
		if(key>=arr[s] && key<=arr[mid])
			return binary_search(arr,s,mid-1,key);
		else
			return binary_search(arr,mid+1,e,key);
	}
	if(key>=arr[mid] && key<=arr[e])
	{
		return binary_search(arr,mid+1,e,key);
	}
	return binary_search(arr,s,mid-1,key);
}
*/
int binary_search(int arr[],int s,int e,int key)
{
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(arr[mid]==key)
			return mid;
		if(arr[s]<=arr[mid])
		{
			if(key>=arr[s] && key<=arr[mid])
			{
				e=mid-1;
				continue;
			}
			else{
				s=mid+1;
				continue;
			}
		}
		if(key>=arr[mid] && key<=arr[e])
		{
			s=mid+1;
			continue;
		}
		e=mid-1;
	}
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
	int key;
	cin>>key;
	int pos=binary_search(arr,0,n-1,key);
	cout<<pos<<endl;
}