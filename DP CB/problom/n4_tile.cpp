#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int tile(int n)
{
	if(dp[n]!=0) return dp[n];
	for(int i=5;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-4];
	}
	return dp[n];
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<4;i++) dp[i]=1;
		dp[4]=2;
		int n;
		cin>>n;
		int ans=tile(n);
		cout<<ans<<endl;
	}
}