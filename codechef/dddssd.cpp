#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll m;
pair<ll,ll> mult(pair<ll,ll> A,pair<ll,ll> B)
{
	pair<ll,ll>ans;
	ans.first=((A.first*B.first+m)%m-(A.second*B.second+m)%m+m)%m;
	ans.second=((A.first*B.second+m)%m+(A.second*B.first+m)%m+m)%m;
	return ans;
}
pair<ll,ll> binexp(ll a,ll b,ll k)
{
	if(k==0)
	{
		pair<ll,ll> a1=make_pair(1,0);
	//	cout<<a1.first<<" "<<a1.second<<endl;
		return a1;
		
	}
	pair<ll,ll> ans=binexp(a,b,k/2);
	ans=mult(ans,ans);
	if(k&1){
		pair<int,int> aa=make_pair(a,b);
	//	cout<<ans.first<<" "<<ans.second<<endl;
		return mult(aa,ans);
	}
//	cout<<ans.first<<" "<<ans.second<<endl;
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll a,b,k;
		cin>>a>>b>>k>>m;
		pair<ll,ll> ans=binexp(a,b,k);
		cout<<ans.first<<" "<<ans.second<<endl;
	}
}
