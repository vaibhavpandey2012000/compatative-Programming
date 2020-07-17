#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll fib(ll n,ll dp[])
{
	if(n==0 || n==1)
		return n;
	//hare apply dp
	if(dp[n]!=0)
	{
		return dp[n];
	}

	return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
int main()
{
	ll n,dp[100]={0};
	cin>>n;
	fib(n,dp);
	cout<<fib(n,dp)<<endl;;
}