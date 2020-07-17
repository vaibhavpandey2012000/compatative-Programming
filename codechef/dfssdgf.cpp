#include<bits/stdc++.h>
#define ll long long 
ll arr[200005],dpf[200005],dpb[200005];
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	k--;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=k+1;i<n;i++)
	{
		dpf[i]=arr[i]+max(dpf[i-1],dpf[i-2]);
	}
	dpb[0]=arr[0];
	dpb[1]=arr[0]+arr[1];
	for(int i=2;i<n;i++)
	{
		dpb[i]=arr[i]+max(dpb[i-1],dpb[i-2]);
	}
	ll ans=INT_MIN;
	for(int i=k+1;i<n;i++)
	{
		ans=max(ans,dpf[i]+dpb[i]-arr[i]);
	}
	cout<<ans<<endl;
}
