#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool fxn(vector<ll> arr,ll n,ll m,ll k)
{
	ll sum=0,cnt=1;
	for(int i=0;i<n;i++)
	{
		if(sum+arr[i]<=m)
		{
			sum=sum+arr[i];
		}
		else
		{
			cnt++;
			sum=arr[i];
			if(cnt>k)
			return false;
		}
	}
	return true;
}
ll binerysort(vector<ll> arr,ll n,ll s,ll e,ll k)
{
	ll ans=s;
	while(s<=e)
	{
		ll m=s+(e-s)/2;
		if(fxn(arr,n,m,k)==true)
		{
			ans=m;
			e=m-1;
		}
		else
		{
			s=m+1;
		}
	}
	return ans;
}
int main()
{
	ll n,k;
	cin>>k>>n;
	vector<ll>arr(n);
	ll sum=0,mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
		mx=max(mx,arr[i]);
	}
//	sort(arr.begin(),arr.end());
	ll time=binerysort(arr,n,mx,sum,k);
	cout<<time<<endl;
}