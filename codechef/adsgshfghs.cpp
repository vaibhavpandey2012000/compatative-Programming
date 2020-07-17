#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll,ll>mp;
ll tiling(ll n)
{
	if(n<0) return 0;
	if(n==0) return 1;
	if(n<=2) return n;
	if(mp.count(n)) return mp[n];
	mp[n]=(tiling(n-1)+tiling(n-2))%1000000007;
	return mp[n];
}
int main()
{
	ll n;
	cin>>n;
	ll ans=tiling(n);
	cout<<ans<<endl;
}
