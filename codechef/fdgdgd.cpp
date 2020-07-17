#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;
int cc[maxN];
int mincoin_bottomup(int n,int *arr,int t)
{
	int dp[n+1];
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=INT_MAX;
		for(int j=0;j<t;j++)
		{
			if(i-arr[j]>=0)
			{
				dp[i]=min(dp[i],dp[i-arr[j]]);
			}
		}
		dp[i]++;
	}
	return dp[n];
}
int mincoin_topup(int n,int *arr,int t)
{
	if(n==0)
	return 0;
	if(cc[n]!=0)
	return cc[n];
	int ans1=INT_MAX;
	for(int i=0;i<t;i++)
	{
		if(n-arr[i]>=0)
		ans1=min(ans1,mincoin_topup(n-arr[i],arr,t));	
	}	
	cc[n]=ans1+1;
	return cc[n];
}
int main()
{
	int n,t;
	cin>>n>>t;
	int arr[t];
	for(int i=0;i<t;i++)
	cin>>arr[i];
	cout<<mincoin_bottomup(n,arr,t)<<endl;
	cout<<mincoin_topup(n,arr,t)<<endl;
}
