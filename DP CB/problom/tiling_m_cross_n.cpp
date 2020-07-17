#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
const int maxN=100005;
ll dp[maxN];
ll tiling_prob(int m,int n)
{
	if(dp[n]!=0) return dp[n]%MOD;
	for(int i=m+1;i<=n;i++)
	dp[i]=(dp[i-1]+dp[i-m])%MOD;
	return dp[n];
}
int main(){
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=n;i++)
		{
			if(i<m)
			dp[i]=1;
			else if(i==m)
			dp[i]=2;
			else
			dp[i]=0;
		}
		ll ans=tiling_prob(m,n);
		
		cout<<(ans+MOD)%MOD<<endl;
	}
}