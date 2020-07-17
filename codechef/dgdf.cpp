#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define MOD 1000000007
ll powr(ll a,ll n,ll d)
{
	ll res=1;
	while(n)
	{
		if(n&1)
		res=((res%d)*(a%d))%d ,n--;
		else
		res=((a%d)*(a%d))%d ,n=(n>>1);
	}
	return res;
}
ll gcd(ll a,ll b,ll n)
{
	if(a==b)
	{
		return (powr(a,n,MOD)+powr(b,n,MOD))%MOD;
	}
	ll num=abs(a-b);
	ll ans=1;
	for(ll i=1;i*i<=num;i++)
	{
		if(num%i==0)
		{
			ll temp=(powr(a,n,i)+powr(b,n,i))%i;
			if(temp==0)
			ans=max(ans,i);
			temp=(powr(a,n,num/i)+powr(b,n,num/i))%(num/i);
			if(temp==0)
			ans=max(ans,n/i);
		}
	}
	return ans%MOD;
}
int main()
{
	ll tc,a,b,n;
	cin>>tc;
	while(tc--)
	{
		cin>>a>>b>>n;
		cout<<gcd(a,b,n)<<endl;
	}
}
