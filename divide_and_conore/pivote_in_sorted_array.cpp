#include<bits/stdc++.h>
using namespace std;
int binery_search(int *arr,int s,int e)
{
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(arr[mid]<arr[mid-1] && mid-1>=s)
		{
			return mid-1;
		}
		if(arr[mid]>arr[mid+1] && mid+1<=e)
		{
			return mid;
		}
		if(arr[mid]<arr[s])
		{
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	return e;
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
	int ans =binery_search(arr,0,n-1);
	cout<<ans<<endl;
}