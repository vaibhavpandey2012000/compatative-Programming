#include<bits/stdc++.h>
using namespace std;
int ladder(int n,int k,int *dp)
{
	if(n==0) return 1;
	if(dp[n]!=0) return dp[n];
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		if((n-k)>=0)
		ans+=ladder(n-i,k,dp);
	}
	return dp[n]=ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int dp[1000]={0};
	int ans=ladder(n,k,dp);
	cout<<ans<<endl;
}
