#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
const int mx=100000+5;
int n,m;
ll tiling_prob(int N,ll dp[])
{
	if(dp[N]!=0)
	return dp[N];
	else
	return dp[N]=(tiling_prob(N-1,dp)%MOD+tiling_prob(N-m,dp)%MOD)%MOD;
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll dp[mx];
		memset(dp,0,sizeof(dp));
		cin>>n>>m;
		dp[0]=0;
		for(int i=1;i<m;i++)
		{
			dp[i]=1;
		}
		dp[m]=2;
		ll ans=tiling_prob(n,dp);
		cout<<ans<<endl;
	}
}