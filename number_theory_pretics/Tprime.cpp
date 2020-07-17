#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool isprime(ll n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n;
		cin>>n;
		ll p=sqrt(n);
		if(n==0 || n==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(p*p!=n)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			bool ans=isprime(p);
			if(ans==true)
			{
				cout<<"YES"<<endl;
				continue;
			}
			else
			{
				cout<<"NO"<<endl;
				continue;
			}
		}
	}
}