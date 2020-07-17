#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll power(ll a,ll b)
{
	if(b==0) return 0;
	ll ans=power(a,b/2);
	ans=((ans%MOD)*(ans%MOD))%MOD;
	if(b&1)
	return ((ans%MOD)*(a%MOD))%MOD;
	else
	return ans;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ll ans=power(b,c);
		ll ans1=power(a,ans);
		cout<<ans1<<endl;
	}
}
