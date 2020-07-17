#include<bits/stdc++.h>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;
ll dp[100005];
ll tiling_prob(int n,int m)
{
	if(n<m)
	return 1;
	if(n==m)
	return 2;
	if(dp[n]!=0)
	return dp[n];
	ll ans=(tiling_prob(n-1,m)+tiling_prob(n-m,m))%MOD;
	dp[n]=ans;
	return dp[n];
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		memset(dp,0,sizeof(dp));
		int n,m;
		cin>>n>>m;
		ll ans=tiling_prob(n,m);
		cout<<ans<<endl;
	}
}
