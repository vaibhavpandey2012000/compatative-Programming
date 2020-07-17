#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int p[100000];
void seave()
{
	for(int i=0;i<=100000;i++)
		p[i]=1;
	for(int i=2;i<=100000;i++)
	{
		if(p[i])
		{
			for(int j=i*i;j<=100000;j+=i)
			{
				p[j]=0;
			}
		}
	}
}
int segmented_seave(ll a,ll b)
{
	seave();
	bool pp[b-a+1];
	memset(pp,1,sizeof(pp));
	for(ll i=2;i*i<=b;i++)
	{
		for(ll j=a;j<=b;j++)
		{
			if(p[i])
			{
				if(j==i)
					continue;
				if(j%i==0)
					pp[j-a]=0;
			}
		}
	}
	int res=1;
	for(ll i=a;i<=b;i++)
	{
		res+=(pp[i-a]);
	}
	return res;
}
int main()
{
	ll a,b;
	cin>>a>>b;
	cout<<segmented_seave(a,b)<<endl;
}