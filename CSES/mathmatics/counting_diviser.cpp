#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll ans=1;
		for(int i=2;i*i<=n;i++)
		{
			ll cnt=0;
			while(n%i==0)
			{
				cnt++;
				n=n/i;
			}
			if(cnt)
			ans*=(cnt+1);
		}
		if(n>1)
		ans*=2ll;
		cout<<ans<<endl;
	}
}