#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int min_jump(int *arr,int n)
{
	int dis[n],ind[n];
	for(int i=0;i<n;i++) dis[i]=inf;
	dis[0]=0;
	ind[0]=-1;
	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<=arr[i];j++)
		{
			if(dis[i+j]>dis[i]+1)
			{
				dis[i+j]=dis[i]+1;
				ind[i+j]=i;
			}
		}
	}
	for(int i=0;i<n;i++) cout<<setw(2)<<dis[i];
	cout<<endl;
	for(int i=0;i<n;i++) cout<<setw(2)<<ind[i];
	cout<<endl;
	return dis[n-1];
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans=min_jump(arr,n);
	cout<<ans<<endl;
}
