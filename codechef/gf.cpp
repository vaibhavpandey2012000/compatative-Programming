#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		ll mx=0,curr=0;
		for(int i=0;i+1<n;i+=2)
		{
			curr+=(arr[i+1]-arr[i]);
			curr=max(0ll,curr);
			mx=max(curr,mx);
		}
		curr=0;
		for(int i=1;i+1<n;i+=2)
		{
			curr+=(arr[i]-arr[i+1]);
			curr=max(0ll,curr);
			mx=max(curr,mx);
		}
		ll ans=0;
		for(int i=0;i<n;i+=2)
		{
			ans+=arr[i];
		}
		cout<<ans+mx<<endl;
		
	}
}
