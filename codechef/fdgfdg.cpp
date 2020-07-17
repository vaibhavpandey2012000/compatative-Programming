#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll friend_pair(int n)
{
	ll dp[n];
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+(i-1)*dp[i-2];
	}
	return dp[n];
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll ans=friend_pair(n);
		cout<<ans<<endl;
	}
}
