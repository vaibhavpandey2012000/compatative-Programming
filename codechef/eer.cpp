#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int dp[1000];
ll catlennumber(int n)
{
	if(n==0||n==1)
	return 1;
	if(dp[n]!=0)
	return dp[n];
	for(int i=1;i<=n;i++)
	{
		ll f1=catlennumber(i-1);
		ll f2=catlennumber(n-i);
		dp[n]+=f1*f2;
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	cout<<catlennumber(n)<<endl;
}
