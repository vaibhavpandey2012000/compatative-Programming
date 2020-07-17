#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll F[10001];
fact()
{
	ll ans=1;
	for(int i=1;i<=100000;i++)
	{
		F[i]=(ans*i)%MOD;
	}
}
ll inv(ll a,ll n)
{
	ll res=1;
	while(n)
	{
		if(n&1)
		res=(res*a)%MOD ,n--;
		else
		a=(a*a)%MOD ,n=(n/2);
	}
	return res;
}
ll NCR(int n,int k)
{
	if(n<k) return -1;
	ll ans=F[n];
	ans=ans* inv(F[k],MOD-2);
	ans=ans* inv(F[n-k],MOD-2);
	return ans;
}
int main()
{
	fact();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		ll ans=NCR(n,k);
		cout<<ans<<endl;
	}
}