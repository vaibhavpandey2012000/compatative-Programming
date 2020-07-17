#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
bool fun(vector<ll> v,ll mid)
{
	ll sum=0,cnt=1;
	for(int i=0;i<n;i++)
	{
		if(sum+v[i]<=mid)
		{
			sum+=v[i];
		}
		else{
			cnt++;
			sum=v[i];
			if(cnt>m)
			return false;
		}
	}
	return true;
}
ll binerysearch(vector<ll> v,ll s,ll e)
{
	ll ans=INT_MAX;
	while(s<=e)
	{
		ll mid=(s+e)/2;
		if(fun(v,mid)==true)
		{
			ans=min(ans,mid);
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	vector<ll>v(n);
	ll s=INT_MAX,e=0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		s=min(s,v[i]);
		e+=v[i];
	}
	ll ans=binerysearch(v,s,e);
	cout<<ans<<endl;
}