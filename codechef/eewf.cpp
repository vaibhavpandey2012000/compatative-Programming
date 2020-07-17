#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define MOD 1000000007
int arr[500000],pre[50000],suf[50000];
ll power(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) {
			ans=(ans*a)%MOD;
			b--;
		}
		else
		{
			a=(a*a)%MOD;
			b=b/2;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	rep(i,n) 
	{
		cin>>arr[i];
		pre[i]=(arr[i]+pre[i-1])%MOD;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ll sum=(pre[j]-pre[i-1])%MOD;
			cout<<sum<<" ";
			sum=power(2ll,sum);
			cout<<sum<<endl;
			ans=(ans+sum)%MOD;
		}
	}
	cout<<ans<<endl;
}
