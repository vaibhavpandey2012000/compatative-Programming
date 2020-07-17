#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll grandy[100005];

 unordered_set<ll> factor(ll n)
{
	unordered_set<ll>ans;
	for(int i=2;i*i<=n;i++)
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
ll calcmex(unordered_set<ll> s)
{
	int p=0;
	while(s.find(p)!=s.end())
	p++;
	return p;
}
ll calcgrandy(ll m)
{
	if(m==0)
	return 0;
	
	if(grandy[m]!=0)
	return grandy[m];
	
	unordered_set<ll> factor=factor(m);
	unordered_set<ll> s;
	for(auto e:factor)
	{
		s.insert(calcgrandy(e));
	}
	return grandy[m]=calcmex(s);
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n,m;
		cin>>n>>m;
		ll ans=calcgrandy(m);
		if(n%2==0)
		{
			cout<<"2"<<endl;
		}
		else
		{
			if(ans==0)
			cout<<"2"<<endl;
			else
			cout<<"1"<<endl;
		}
	}
}
