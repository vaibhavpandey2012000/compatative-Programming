#include<bits/stdc++.h>
using namespace std;
const int maxN=1000;
int arr[maxN],dp[maxN];
//dp subarrysum
int subaraysum(int *arr,int n)
{
	dp[0]=arr[0]>0?arr[0]:0;
	int maxsum=dp[0];
	for(int i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+arr[i];
		if(dp[i]<0)
		dp[i]=0;
		maxsum=max(maxsum,dp[i]);
	}
	return maxsum;
}
//space optimize
int subarraysum(int *arr,int n)
{
	int currsum=0;
	int maxsum=0;
	for(int i=0;i<n;i++)
	{
		currsum+=arr[i];
		if(currsum<0)
		currsum=0;
		maxsum=max(maxsum,currsum);
	}
	return maxsum;
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i],dp[i]=0;
		int maxsum=subarraysum(arr,n);
		cout<<maxsum<<endl;
	}
	
}