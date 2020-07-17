#include<bits/stdc++.h>
using namespace std;
int ladder(int n,int k)
{
	int dp[n+1]={0};
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		if(i-j>=0)
		dp[i]+=dp[i-j];
	}
	return dp[n];
}
int ladder_opt(int n,int k)
{
	int dp[100]={0};
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++)
	if(i<=k)
	dp[i]=2*dp[i-1];
	else
	dp[i]=2*dp[i-1]-dp[i-k-1];
	return dp[n];
}
int main(){
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		int ans=ladder(n,k);
		int ans2=ladder_opt(n,k);
		cout<<ans<<" "<<ans2<<endl;
	}
}
