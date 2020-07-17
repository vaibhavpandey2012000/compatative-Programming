#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll fibo(ll n)// t(n)=o(n),s(n)=o(n);
{
	long dp[100]={0};
	dp[0]=0,dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}
ll fib(ll n)// t(n)=o(n),s(n)=o(1)
{
	if(n==0 || n==1)
	{
		return n;
	}
	ll a=0,b=1,c;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
int main()
{
	ll n;
	cin>>n;
	cout<<fib(n)<<endl;;
}