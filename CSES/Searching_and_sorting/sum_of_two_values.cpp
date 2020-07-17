#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll n,x,flg=0;
	cin>>n>>x;
	map<ll,ll>mp;
	for(int i=1;i<=n;i++)
	{
		ll temp;
		cin>>temp;
		ll kk=x-temp;
		if(mp.find(kk)!=mp.end())
		{
			flg=1;
			cout<<mp[kk]<<" "<<i<<endl;
			break;
		}
		mp[temp]=i;
	}
	if(flg==0)
	cout<<"IMPOSSIBLE"<<endl;
}