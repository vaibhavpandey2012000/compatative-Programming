#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int dp[10005];
int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	dp[0]=1;
	for(int i=1;i<=k;i++)
	{
		if(arr[i]!=1)
		for(int j=i-1;j>=0;j--)
		dp[i]+=dp[j];
	}
	for(int i=k+1;i<=n;i++)
	{
		if(arr[i]!=1)
		{
			for(int j=i-1;j>=i-k;j--)
			dp[i]+=dp[j];
		}
	}
	for(int i=0;i<=n;i++)
	cout<<dp[i]<<" ";
	
}
