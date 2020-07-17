#include<bits/stdc++.h>
using namespace std;
int binery_search(int arr[],int s,int e)
{
	while(s<=e)
	{
		int mid=(s+e)/2;
		//cout<<s<<" "<<e<<" "<<mid<<" "<<endl;
		if(arr[mid]>arr[mid+1] && mid<e)
		{
			return mid;
			break;
		}
		if(arr[mid-1]>arr[mid] && mid>s)
		{
			return mid-1;
			break;
		}
		if(arr[s]>=arr[mid])
		{
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	//return s-1;
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
	int pos=binery_search(arr,0,n-1);
	cout<<endl;
	cout<<pos+1<<endl;
}