#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll,ll>mp;
ll solve(ll n)
{
	if(n<=11)
	return n;
	if(mp.count(n)) return mp[n];
	mp[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
	return mp[n];
	
}
int main()
{
	ll n;
	cin>>n;
	if(n==0){
		cout<<"0"<<endl;
		return 0;
	}
	ll ans=solve(n);
//	for(auto e:mp)
//	cout<<e.first<<" "<<e.second<<",";
	cout<<ans<<endl;
}
