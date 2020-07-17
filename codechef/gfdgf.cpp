#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
ll arr[100001];
ll INV(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%MOD,b--;
		else a=(a*a)%MOD,b=(b>>1);
	}
	return ans;
}
ll C(int n,int k)
{
	if(k>n) return 0;
	ll ans=1;
	ans*=arr[n];
	ans=(ans*1ll*INV(arr[k],MOD-2))%MOD;
	ans=(ans*1ll*INV(arr[n-k],MOD-2))%MOD;
	return ans;
}
int main()
{
	arr[0]=arr[1]=1;
	for(int i=2;i<100000;i++)
	{
		arr[i]=(arr[i-1]*i)%MOD;
	}
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n,k;
		cin>>n>>k;
		ll ans=C(n,k);
		cout<<ans<<endl;
	}
}
