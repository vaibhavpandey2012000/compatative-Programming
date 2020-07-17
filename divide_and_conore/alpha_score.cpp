#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll merge(ll *arr,int s,int e)
{
	ll a[10000];
	ll ans=0;
	int mid=(s+e)/2;
	int i=s,j=s,k=mid+1;
	while(i<=mid && k<=e)
	{
		if(arr[i]<arr[k])
		{
			a[j++]=arr[i++];
		}
		else
		{
			ans=(ans+(arr[k]*(mid-i+1))%MOD)%MOD;
			a[j++]=arr[k++];
		}
	}
	while(i<=mid)
	{
		a[j++]=arr[i++];
	}
	while(k<=e)
	{
		a[j++]=arr[k++];
	}
	for(int i=s;i<=e;i++)
	{
		arr[i]=a[i];
	}
	return ans;
}
ll merge_sort(ll *arr,int s,int e)
{
	if(s>=e)
	return 0;
	int mid=(s+e)/2;
	ll pp=merge_sort(arr,s,mid);
	ll qq=merge_sort(arr,mid+1,e);
	ll rr=merge(arr,s,e);
	return (pp+qq+rr)%MOD;
}
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll ans=merge_sort(arr,0,n-1);
//	for(int i=0;i<n;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
	cout<<ans<<endl;
}