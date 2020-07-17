#include<bits/stdc++.h>
using namespace std;
const int MX=100000+5;
long dp[MX]={0};
long count(int n)
{
	if(n==0 || n==1 || n==2)
	{
		dp[n]=n;
	}
	if(dp[n]!=0)
	return dp[n];
	long ans=count(n-1)+(n-1)*count(n-2);
	return dp[n]=ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		if(n==0)
		{
			cout<<"0"<<endl;
			continue;
		}
		long ans=count(n);
		cout<<ans<<endl;
	}
}