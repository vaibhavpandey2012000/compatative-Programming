#include<bits/stdc++.h>
# define ll unsigned long long
using namespace std;
int primes[]={2,3,5,7,11,13,17,19};
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n,ans=0;
		cin>>n;
		int mask=(1<<8)-1;
		for(int i=1;i<=mask;i++)
		{
			ll denom=1ll;
			ll count=__builtin_popcount(i);

			for(int j=0;j<8;j++)
			{
				if(i&(1<<j))
					denom=denom*primes[j];
			}
			if(count&1)
			{
				ans+=n/denom;
			}
			else
			{
				ans-=n/denom;
			}

		}
		cout<<ans<<endl;

	}
}