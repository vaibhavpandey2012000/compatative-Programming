#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
ll fact[10000001];
void seave()
{
	fact[0]=1;
	for(int i=1;i<1000001;i++)
	fact[i]=(fact[i-1]*i)%MOD;
}
ll inv(ll a,ll b)
{
	if(b==0)return 1;
	ll ans=inv(a,b/2);
	ans=((ans%MOD)*(ans%MOD))%MOD;
	if(b&1) ans=(ans*a)%MOD;
	return ans;
}
ll C(int a,int b)
{
	if(b>a) return 0;
	ll ans=fact[a];
	ans=(ans* inv(fact[b],MOD-2))%MOD;
	ans=(ans* inv(fact[a-b],MOD-2))%MOD;
	return ans;
}
int main()
{
	seave();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a,b;
		cin>>a>>b;
		cout<<C(a,b)<<endl;
	}
}