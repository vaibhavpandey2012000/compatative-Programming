#include<bits/stdc++.h>
using namespace std;
/*int binery_search(int *arr,int n,int el)
{
	int ans=-1,s=0,e=n-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(arr[mid]==el)
		return mid;
		if(arr[mid]<el)
		s=mid+1;
		else
		e=mid-1;
	}
	return -1;
}*/
/*
int binery_search(int *arr,int s,int e,int ele)
{
	if(s>e) return -1;
	int mid=(s+e)/2;
	if(arr[mid]==ele) return mid;
	if(arr[mid]<ele) return binery_search(arr,mid+1,e,ele);
	else
	return binery_search(arr,0,mid-1,ele);
}
*/
int binery_search(int *arr,int n,int ele)
{
	int k=0;
	for(int b=n/2;b>=1;b/=2)
	{
		while(k+b<n && arr[k+b]<=ele) k+=b;
	}
	if(arr[k]==ele)
	return k;
	return -1;
}
int main()
{
	int arr[]={1,4,6,8,11,23,25,43,52};
	int n=9;
	int p=binery_search(arr,n,7);
	cout<<p;
}
