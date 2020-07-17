#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n,k;
		cin>>n>>k;
		ll ans=1;
		for(ll i=1;i*i<=n;i++)
		{
			if(n%i==0 && i<=k)
			{
				ans=max(ans,i);
				if(n/i<=k)
				ans=max(ans,n/i);
			}
		}
		//cout<<ans<<endl;
		cout<<n/ans<<endl;
	}
}
