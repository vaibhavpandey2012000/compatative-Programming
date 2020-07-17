#include<bits/stdc++.h>
using namespace std;
int max_change(int *coin,int s,int n)
{
	if(n==0 || s==0) return 0;
	int arr[n+1][s+1];
	for(int j=0;j<=s;j++)
	arr[0][j]=0;
	for(int i=0;i<=n;i++)
	arr[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			int inclusive=0;
			int exclusive=0;
			if(j-coin[i-1]>=0)
			inclusive=arr[i][j-coin[i-1]];
			exclusive=arr[i-1][j];
			arr[i][j]=inclusive+exclusive;
		}
	}
	return arr[n][s];
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
