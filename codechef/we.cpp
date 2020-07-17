#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll calc(ll n)
{
	ll ans=(n*n)*(n*n-1)-(8)-(24)-((n-4)*16)-(16)-(24*(n-4))-(8*(n-4)*(n-4));
	cout<<ans/2<<endl;
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		calc(i);
	}
}
