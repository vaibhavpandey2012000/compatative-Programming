#include<bits/stdc++.h>
using namespace std;
int max_seq(int *arr,int n)
{
	int dp[n];
	for(int i=0;i<n;i++) dp[i]=1;
	int mx=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i] && dp[j]+1>dp[i])
			dp[i]=max(dp[j]+1,dp[i]);
		}
		mx=max(dp[i],mx);
	}
	for(int i=0;i<n;i++) cout<<dp[i]<<" ";
	cout<<endl;
	return mx;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int ans=max_seq(arr,n);
	cout<<ans<<endl;
}
