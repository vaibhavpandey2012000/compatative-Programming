#include<bits/stdc++.h>
using namespace std;
int binary_search(int *arr,int s,int e,int ele)
{
	if(s>e)
		return -1;
	int mid=(s+e)/2;
	if(arr[mid]==ele)
	{
		return mid;
	}
	if(arr[mid]>ele)
	{
		binary_search(arr,s,mid-1,ele);
	}
	else
	{
		binary_search(arr,mid+1,e,ele);
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
	int ele;
	cin>>ele;
	int p=binary_search(arr,0,n-1,ele);
	if(p==-1)
		cout<<"element not present"<<endl;
	else
		cout<<"element present at:"<<p+1<<"th index."<<endl;

}