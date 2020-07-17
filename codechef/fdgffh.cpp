#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll powr(ll a,ll b,ll m)
{
	if(b==0) return 1;
	ll ans=powr(a,b/2,m);
	ans=((ans%m) * (ans%m))%m;
	if(b&1) ans=((ans%m)*(a%m))%m;
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ll x=powr(b,c,MOD-1);
		ll ans=powr(a,x,MOD);
		cout<<ans<<endl;
	}
}
