#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll power(ll a,ll b)
{
	if(b==0) return 1ll;
	ll ans=power(a,b/2);
	ans=((ans%MOD)*(ans%MOD))%MOD;
	if(b&1) ans=((ans%MOD)*(a%MOD))%MOD;
	return ans;
}
int main()
{
	ll n;
	cin>>n;
	ll ans=power(2ll,n);
	cout<<ans<<endl;
}