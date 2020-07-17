#include<bits/stdc++.h>
using namespace std;
int longet_incressing_subseq(int *arr,int n)
{
	int dp[n];
	for(int i=0;i<n;i++) dp[i]=arr[i];
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int mp=dp[i];
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i] && mp+dp[j]>dp[i])
			{
				dp[i]=mp+dp[j];
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
		ans=max(ans,dp[i]);
	}
	cout<<endl;
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