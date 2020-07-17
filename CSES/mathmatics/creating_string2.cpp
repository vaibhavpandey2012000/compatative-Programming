#include<bits/stdc++.h>
#define MOD 1000000007
#define ll  long long
using namespace std;
ll fact[10000001];
void seave()
{
	fact[0]=1;
	for(int i=1;i<100001;i++)
	fact[i]=(fact[i-1]*i)%MOD;
}
ll inv(ll a,ll b)
{
	if(b==0)return 1;
	ll ans=inv(a,b/2);
	ans=((ans%MOD)*(ans%MOD))%MOD;
	if(b&1) ans=(ans*a)%MOD;
	return ans;
}
int main()
{
	seave();
	string s;
	cin>>s;
	cout<<s.length()<<endl;
	map<char,ll>mp;
	for(ll i=0;i<s.length();i++)
	mp[s[i]]++;
	ll ans=fact[s.length()];
	for(auto e:mp)
	{
		ans=(ans*(inv(fact[e.second],MOD-2)))%MOD;
	}
	cout<<ans<<endl;
}