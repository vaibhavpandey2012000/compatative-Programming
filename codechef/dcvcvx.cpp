#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll dp[205]={0};
ll CLT(int n)
{
	if(n==0 || n==1)
	return 1;
	if(dp[n]!=0) return dp[n];
	
	for(int i=1;i<=n;i++)
	{
		ll pp=CLT(i-1);
		ll ss=CLT(n-i);
		dp[n]+=pp*ss;
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	dp[1]=dp[0]=1;
	ll ans=CLT(n);
	cout<<ans<<endl;
	
}
