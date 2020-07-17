#include<bits/stdc++.h>
using namespace std;
int max_change(int *coin,int s,int n)
{
	if(n==0 || s==0) return 0;
	int arr[n][s+1];
	for(int i=0;i<n;i++)
	arr[i][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			int includecoin=0;
			int excludecoin=0;
			if(j-coin[i]>=0)
			{
				includecoin=arr[i][j-coin[i]];
			}
			if(i>0)
			{
				excludecoin=arr[i-1][j];
			}
			arr[i][j]=includecoin+excludecoin;
		}
	}
	return arr[n-1][s];
}
int main()
{
	int n,sum;
	cin>>n>>sum;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans=max_change(arr,sum,n);
	cout<<ans<<endl;
}