#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll power(ll a,ll b)
{
	if(b==0) return 1;
	ll ans=power(a,b/2);
	ans=((ans%MOD)*(ans%MOD))%MOD;
	if(b&1) ans=(ans*a)%MOD;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int>v(n+1);
	v[0]=1;
	for(int i=1;i<=n;i++)
	{
		ll temp;
		cin>>temp;
		v[i]=((power(2ll,temp)+1)*v[i-1])%MOD;
	}
	cout<<v[n]-1<<endl;
	
}
