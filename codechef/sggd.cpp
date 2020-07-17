#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x,y,z;
	cin>>x>>y>>z;
	int dp[n+1];
	dp[0]=dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(i&1)
		{
			int c1=dp[i-1]+y;
			int c2=dp[(i+1)/2]+x+z;
			dp[i]=min(c1,c2);
		}
		else
		{
			int c1=dp[i-1]+y;
			int c2=dp[i/2]+x;
			dp[i]=min(c1,c2);
		}
	}
//	for(int i=0;i<=n;i++)
//	cout<<dp[i]<<" ";
//	cout<<endl;
	cout<<dp[n]<<endl;
}
