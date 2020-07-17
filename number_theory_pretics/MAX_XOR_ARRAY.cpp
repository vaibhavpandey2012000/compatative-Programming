#include<bits/stdc++.h>
# define ll unsigned long long
using namespace std;
bool comp(ll a,ll b)
{
	return a>b;
}
int main()
{
	int n;
	cin>>n;
	ll ans=0;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n,comp);
//	for(int i=0;i<n;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
	for(int i=0;i<n;i++)
	{
		ll temp;
		temp=arr[i];
		ll ans_temp=ans^temp;
		if(ans_temp>ans)
		{
			ans=ans_temp;
		}
	}
	cout<<ans<<endl;
}