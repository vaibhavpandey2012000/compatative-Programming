#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll pow(int a,int b)
{
	if(b==0)
	return 1;
	int ans=pow(a,b/2);
	ans=(ans%MOD * ans%MOD)%MOD;
	if(b&1)
	ans=(ans*a)%MOD;
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll arr[n];
		ll mn=LONG_MAX;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			mn=min(mn,arr[i]);
		}
		if(mn>1)
		{
			cout<<pow(2,n)%MOD;
			continue;
		}
		sort(arr,arr+n);
		ll ans=1;
		 if(mn==1)
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i]==1)
				{
					ans=(ans+(2*pow(2,n-(i+1)))%MOD)%MOD;
				}
				else
				{
					ans=(ans+(1*pow(2,n-(i+1)))%MOD)%MOD;
				}
			}
		}
		cout<<ans<<endl;
	}
}
