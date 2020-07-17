#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
		{
			if(b==0)
				return a;
			return gcd(b,a%b);
		}
	ll x,y,GCD;
void extended_euclidian(ll a,ll b)
{
	if(b==0)
	{
		x=1;
		y=0;
		GCD=a;
		//cout<<x<<" "<<y<<endl;
		return;
	}
	extended_euclidian(b,a%b);
	ll cx=y;
	ll cy=x-(a/b)*y;
	//cout<<cx<<" "<<cy<<endl;
	x=cx;
	y=cy;
}
ll modulo_inverse(ll a,ll m)
{
 	extended_euclidian(a,m);
	return (x+m)%m;
}
int main()
{
	ll n;
	cin>>n;
	vector<ll> arr(n),rem(n),pp(n),inv(n);
	ll prod=1;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		prod=(prod*arr[i]);
	}
	for(ll i=0;i<n;i++)
	{
		cin>>rem[i];
		pp[i]=prod/arr[i];
	}
	for(ll i=0;i<n;i++)
	{
		inv[i]=modulo_inverse(pp[i],arr[i]);
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		ans=(ans+((rem[i]%prod)*(pp[i]%prod)*(inv[i]%prod))%prod)%prod;
	}
	cout<<ans<<endl;
	
}