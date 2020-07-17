#include<bits/stdc++.h>
#define  ll long long int
using namespace std;
ll n,k;
bool fun(ll *arr,ll m)
{
	ll p=1;
	ll pos=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]-pos>=m)
		{
			pos=arr[i];
			p++;
			if(p==k)
			return true;
		}
	}
	return false;
}
ll binarysearch(ll *arr,ll s,ll e)
{
	ll ans=0;
	while(s<=e)
	{
		int m=(s+e)/2;
		if(fun(arr,m)==true)
		{
			ans=m;
			s=m+1;
		}
		else
		{
			e=m-1;
		}
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll ans=binarysearch(arr,0,arr[n-1]);
	cout<<ans<<endl;
}