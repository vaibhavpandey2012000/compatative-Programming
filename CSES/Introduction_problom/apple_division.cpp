#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll make_subset(vector<ll> v,int p,int n)
{
//	cout<<p<<".";
	ll ss=0;
	int ind=0;
	while(p)
	{
		if(p&1)
		ss+=v[ind];//cout<<v[ind]<<",";
		p=(p>>1);
		ind++;
	}
//	cout<<"-->"<<ss<<endl;
	return ss;
}
ll subset(vector<ll> v,int n,ll sum)
{
	ll ans=INT_MAX;
	for(int i=1;i<(1<<n);i++)
	{
		ll s1=make_subset(v,i,n);
		ll s2=sum-s1;
		ans=min(abs(s1-s2),ans);
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<ll> v(n);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	ll ans=subset(v,n,sum);
	cout<<ans<<endl;
}