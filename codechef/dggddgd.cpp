#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}
int main()
{
	int n;
	cin>>n;
	vector<pair<ll,ll> >vp;
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		vp.push_back({a,b});
	}
	sort(vp.begin(),vp.end(),comp);
//	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cout<<vp[i].first<<" "<<vp[i].second<<endl;
//	}
	int ans=1;
	ll deadline=vp[0].second;
	for(int i=1;i<n;i++)
	{
		if(vp[i].first>=deadline)
		{
			ans++;
			deadline=vp[i].second;
		}
		
	}
	cout<<ans<<endl;
}
