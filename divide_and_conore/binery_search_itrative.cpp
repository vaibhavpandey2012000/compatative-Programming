#include<bits/stdc++.h>
using namespace std;
int binery_search(int a[],int s,int e,int ele)
{
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(a[mid]==ele)
		{
			return mid+1;
		}
		else if(ele>a[mid])
		{
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	return -1;
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
	int position=binery_search(arr,0,n-1,ele);
	if(position==-1)
	{
		cout<<"element is not found."<<endl;
	}
	else
	{
		cout<<"element is at position "<<position<<endl;
	}
}