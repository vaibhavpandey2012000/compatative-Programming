#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		ll ans=1ll;
		cin>>n;
		map<ll,ll>mp;
		for(int i=0;i<n;i++)
		{
			ll num;
			cin>>num;
			for(int j=2;j*j<=num;j++)
			{
				while(num%j==0)
				{
					mp[j]++;
					num=num/j;
				}
			}
			if(num>2)
			{
				mp[num]++;
			}
		}
		for(auto i:mp)
		{
			ans=(ans*(i.second+1))%MOD;
		}
		cout<<(ans+MOD)%MOD<<endl;
	}
}