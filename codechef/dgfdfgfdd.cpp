#include<bits/stdc++.h>
using namespace std;
int dp[100];
int min_coin(int *coin,int n,int s)
{
	if(s==0 || n==0) return 0; 
	int arr[n+1][s+1];
	for(int i=0;i<=n;i++)arr[i][0]=0;
	for(int j=0;j<=s;j++) arr[0][j]=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			int inc=INT_MAX;
			if(j-coin[i-1]>=0)
			inc=1+arr[i][j-coin[i-1]];
			int exc=arr[i-1][j];
			arr[i][j]=min(inc,exc);
		}
	}
	return arr[n][s];
}
int main()
{
	int n,s;
	cin>>n>>s;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans=min_coin(arr,n,s);
	cout<<ans<<endl;
}
