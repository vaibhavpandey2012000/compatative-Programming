#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
ll fxn(ll n)
{
	ll sum=0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			sum=(sum+i)%MOD;
			if(n/i!=i)
			sum=(sum+n/i)%MOD;
		}
	}
	return sum%MOD;
}
int main()
{
	ll n;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		sum=(sum+fxn(i+1))%MOD;
	}
//	ll sum=fxn(n);
	cout<<sum<<endl;
}