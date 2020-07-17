#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
ll factor(ll n)
{
	ll ans=1;
	map<ll,ll>mp;
	for(int i=2;i*i<=n;i++)
	{
		int cnt=0;
		while(n%i==0)
		{
			cnt++;
			n=n/i;		
		}
		if(cnt)
		mp[i]=cnt;
		ans=(ans*(cnt+1))%MOD;
	}
	if(n>2)
	{
		ans=(ans*2)%MOD;
		mp[n]++;
	}
	for(auto e:mp)
	{
		cout<<e.first<<" "<<e.second<<endl;
	}
	return ans;
}
int main()
{
	ll tc,n;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		ll ans=factor(n);
		cout<<ans<<endl;
	}
}
