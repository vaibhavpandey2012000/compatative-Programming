#include<bits/stdc++.h>
using namespace std;
int longet_incressing_subseq(int *arr,int n)
{
	int dp[n];
	for(int i=0;i<n;i++) dp[i]=1;
	int ans=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i] && dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
				ans=max(ans,dp[i]);
			}
		}
	}
//	for(int i=0;i<n;i++)
//	cout<<dp[i]<<" ";
//	cout<<endl;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans=longet_incressing_subseq(arr,n);
	cout<<ans<<endl;
}