#include<bits/stdc++.h>
#define ll long long int 
ll func(ll n)
{
    if(n==1)
        return 1;

    if(n==0)
        return 1;
    ll x=func(n/2);
    if(n%2==0)
    {
        x=2*x+1;
    }
    else
    {
        x=2*x+1;
    }
    return x;
}
int ans=0;
void build(ll n,ll l,ll r,ll ql,ll qr)
{
	if(n==1)
	{
		ans++;
		return;
	}
	if(n==0)
	{
		return;
	}
	ll mid=(r-l)/2;
	if(!(ql>(l+mid-1) || (qr<l)))
	{
		build(n/2,l,l+mid-1,ql,qr);
	}
	if(!(ql>r ||(qr<l+mid+1)))
	{
		build(n/2,l+mid+1,r,ql,qr);
	}
	if(((l+mid)>=ql && (l+mid<=qr))&&(n%2==1))
	{
		ans++;
	}
}
using namespace std;
int main()
{
	ll n,l,r;
	cin>>n>>l>>r;
	ll ran=func(n);
	build(n,1,ran,l,r);
	cout<<ans<<endl;
	
}