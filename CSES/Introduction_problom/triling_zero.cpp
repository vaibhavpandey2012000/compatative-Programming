#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
	ll n;
	cin>>n;
	ll p=5;
	int ans=0;
	for(;p<=n;p*=5)
	{
		ans+=n/p;
	}
	cout<<ans<<endl;
}