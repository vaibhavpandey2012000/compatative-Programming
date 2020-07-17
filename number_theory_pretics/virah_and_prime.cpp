#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll a1,a2,a3;
int n,r;
void fact()
{
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans*i)%MOD;
		if(i==n)a1=ans;
		if(i==r)a2=ans;
		if(i==(n-r))a3=ans;
	}
}
ll pow(ll a,ll b)
{
	if(b==0)
	{
		return 1;
	}
	ll ans=pow(a,b/2);
	ans=((ans%MOD)*(ans%MOD))%MOD;
	if(b&1) ans=(ans*a)%MOD;
	return (ans%MOD);
}
int main()
{
	cin>>n>>r;
	ll b=MOD-2;
	if(n==r)
	{
		cout<<"1"<<endl;
		return 0;
	}
	fact();
//	cout<<a1<<" "<<a2<<" "<<a3<<endl;
	ll ans1=(a1%MOD);
	ll ans2=(pow(a2,b))%MOD;
	ll ans3=(pow (a3,b))%MOD;
//	cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	ll ans=(((ans1*ans2)%MOD)*ans3)%MOD;
	cout<<ans<<endl;
}
