#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll grandy[1000005];
unordered_set<ll> factor(ll n)
{
	unordered_set<ll> ans;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans.insert(i);
			ans.insert(n/i);
		}
	}
	ans.insert(1);
	return ans;
}
ll calcmex(unordered_set<int> p)
{
	ll tt=0;
	while(p.find(tt)!=p.end())
	tt++;
	return tt;
}
ll calcgrandy(ll n)
{
	if(n==0)
	return 0;
	if(n==1)
	return 0;
	if(grandy[n]!=0)
	return grandy[n];
	unordered_set<ll> f1=factor(n);
	unordered_set<int> mm;
	for(auto e:f1)
	{
		mm.insert(calcgrandy(e));
	}
	return grandy[n]=calcmex(mm);
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<=m;i++)
		grandy[i]=0;
		if(n%2==0)
		{
			cout<<"2"<<endl;
			continue;
		}
		else{
			ll ans=calcgrandy(m);
			if(ans==0)
			cout<<"2"<<endl;
			else
			cout<<"1"<<endl;
		}
		
	}
}