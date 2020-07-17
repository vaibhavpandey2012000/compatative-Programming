#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,x;
	cin>>n>>x;
	multiset<ll>p;
	for(int i=0;i<n;i++)
	{
		ll temp;
		cin>>temp;
		p.insert(temp);
	}
	int ans=0;
	ll nextv=0;
	while(!p.empty())
	{
		if(nextv==0)
		{
			ans++;
			nextv=x-(*p.begin());
			p.erase(p.begin());	
		}
		else
		{
			auto e=p.lower_bound(nextv);
			if(e==p.begin() && *e>nextv)
			{
				nextv=x-*e;
				ans++;
				p.erase(e);
				continue;
			}
			if(e==p.end() || *e>nextv)
			{
				e--;
			}
			p.erase(e);
			nextv=0;
		}
	}
	cout<<ans<<endl;
}
