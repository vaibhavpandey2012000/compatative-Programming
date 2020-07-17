#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll>v(n);
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		v[i]=v[i]%k;
		mp[v[i]]++;
	}
	int arr[k]={0};
	ll ans=0;
	for(auto e:mp)
	{
		cout<<e.first<<" "<<e.second<<endl;
	}
	for(int i=0;i<k;i++)
	{
		if(arr[i]==0)
		{
			int bb=k-i;
			arr[bb]=1;
			ans+=max(mp[i],mp[bb]);
		}
	}
	cout<<ans<<endl;
	
}
