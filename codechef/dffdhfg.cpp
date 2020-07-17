#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll fact[1000005];
void seave()
{
	fact[0]=1;
	for(int i=1;i<1000000;i++)
	fact[i]=(fact[i-1]*i)%MOD;
}
ll inv(ll a,ll b)
{
	//ll ans=1;
	if(b==0)
	return 1;
	ll ans=inv(a,b/2);
	ans=((ans%MOD)*(ans%MOD))%MOD;
	if(b&1)
	ans=(ans*a)%MOD;
	return ans;
}
int main()
{
	seave();
	string s;
	cin>>s;
	int l=s.length();
	map<char,ll>mp;
	for(int i=0;i<l;i++)
	mp[s[i]]++;
	ll ans=fact[l];
	for(auto e:mp)
	{
		ans=(ans*inv(e.second,MOD-2))%MOD;
	}
	cout<<ans<<endl;
}
