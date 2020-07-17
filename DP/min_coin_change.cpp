#include<bits/stdc++.h>
using namespace std;
int dp[100];
int min_coin(int *arr,int n,int s)
{
	if(s==0) return 0;
	if(dp[s]!=0) return dp[s];
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int pp;
		if(s-arr[i]>=0)
		pp=min_coin(arr,n,s-arr[i]);
		ans=min(ans,pp+1);
	}
	return dp[s]=ans;
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