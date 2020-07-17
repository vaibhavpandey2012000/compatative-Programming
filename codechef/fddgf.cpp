#include<bits/stdc++.h>
using namespace std;
long long solve(int x,int y,int z,int n)
{
	long long *dp=new long long[n+1];
	dp[0]=dp[1]=1;//since initly 1 cell is given
	for(int i=2;i<=n;i++)
	{
		if(i&1)
		{
			dp[i]=min(dp[i/2]+x,dp[i-1]+y);
		}
		else
		{
			dp[i]=min(dp[(i+1)/2]+x+z,dp[i-1]+y);
		}
	}
	return dp[n];
}
int main()
{
	int n;
	int x,y,z;
	cin>>n>>x>>y>>z;
	long long ans=solve(x,y,z,n);
	cout<<ans<<endl;
}
