#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll maxsum(int *arr,int n)
{
	ll dp[n+1]={0};
	dp[0]=(arr[0]>0) ?arr[0]:0;
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+arr[i];
		if(dp[i]<0)
		dp[i]=0;
		ans=max(ans,dp[i]);
	}
	return ans;
}
int spaceopt(int *arr,int n)
{
	ll curr=0,ans=0;
	for(int i=0;i<n;i++)
	{
		curr+=arr[i];
		if(curr<0)
		curr=0;
		ans=max(curr,ans);
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	ll ans=maxsum(arr,n);
	ll ans1=spaceopt(arr,n);
	cout<<ans<<" "<<ans1<<endl;
}
