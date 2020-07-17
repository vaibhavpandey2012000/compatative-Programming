#include<bits/stdc++.h>
using namespace std; 
#define ll long long   
ll getmax(ll bit[],ll i)
{
	ll mx=0;
	while(i>0)
	{
		mx=max(mx,bit[i]);
		i-=(i&-i);
	}
	return mx;
}

void update(ll bit[],ll val,ll ind,int i)
{
	while(i<=ind)
	{
		bit[i]=max(val,bit[i]);
		i+=(i&-i);
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll ar[n],w[n];
			map<ll,ll> m;
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			m[ar[i]]=0;
		}
		for(int i=0;i<n;i++)
		{
			cin>>w[i];
		}
		ll ind=1;
		for(auto &i: m)
		{
			i.second=ind++;
		}
		ll bit[ind+1]={0};
		for(int i=0;i<n;i++)
		{
			ll mx=getmax(bit,m[ar[i]]-1);
			update(bit,mx+w[i],ind,m[ar[i]]);
		}
		cout<<getmax(bit,ind)<<endl;
	}
}