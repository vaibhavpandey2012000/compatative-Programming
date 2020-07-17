#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
bool prime[100005];
vector<ll> v;
void prime_seave()
{
	prime[0]=prime[1]=true;
	for(int i=2;i<100000;i+=2)
	prime[i]=true;
	prime[2]=false;
	for(int i=3;i*i<=100000;i+=2)
	{
		if(prime[i]==false)
		{
			for(int j=i*i;j<=100000;j+=i)
			prime[j]=true;
		}
	}
	ll mul=1;
	for(int i=0;i<1000 ;i++)
	{
		if(prime[i]==false)
		{
			mul*=i;
			if(mul>1000000000000000000)
			break;
			v.push_back(mul);
		}
	}
}
int main()
{
	prime_seave();
//	for(int i=0;i<25;i++)
//	cout<<v[i]<<" ";
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll n;
		cin>>n;
		int i;
		for(i=0;i<25;i++)
		{
			if(v[i]>=n)
			break;
		}
		cout<<i<<endl;
	}
}
