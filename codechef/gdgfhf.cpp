#include<bits/stdc++.h>
#define ll unsigned long long 
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n;
		cin>>n;
		ll cnt=0;
		while(n)
		{
			ll p;
			for(ll i=63;i>=0;i--)
			{
				p=(1ll<<i);
				ll pp=p&n;
				if(pp)
				break;
			}
			cnt+=(p<<1)-1;
			n=n-p;
		}
		cout<<endl;
		cout<<cnt<<endl;
	}
}
