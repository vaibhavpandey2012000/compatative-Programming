#include<bits/stdc++.h>
#define ll int
using namespace std;

int f1(ll *arr,int n)
{
	ll mx=INT_MIN;
	for(int i=0;i<n;i++)
		mx=max(mx,arr[i]);
	if(mx<0)
		return 0;
	else
		return mx;
}

int main()
{
	int n,k;
	cin>>n>>k;
	ll arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	if(k==1)
	{
		cout<<f1(arr,n)<<endl;
		return 0;
	}

	ll dp[n];
	ll mi1,mi2,mx1=INT_MIN,mx2=INT_MIN;
	for(int i=0;i<k;i++)
		if(mx1<arr[i])
			mi1=i,mx1=max(mx1,arr[i]);

	for(int i=0;i<k;i++)
		if(i!=mi1)
		{
			if(arr[i]>mx2)
				mx2=arr[i],mi2=i;

		}
	for(int i=0;i<k;i++)
		dp[i]=arr[i];
//	cout<<mi1<<":"<<mx1<<" "<<mi2<<":"<<mx2<<endl;
	for(int i=1;i<=ceil(n/(k*1.0));i++)
	{
		for(int j=i*k;j<min((i+1)*k,n);j++)
			{
				if(mx2>mx1)
				{
					swap(mx1,mx2);
					swap(mi1,mi2);
				}
				if((j-mi1)%k!=0)
				{
					ll pp=arr[j]+mx1;
					dp[j]=max(mx1,pp);
				}
				else{
					ll pp=arr[j]+mx2;
					dp[j]=max(mx2,pp);
				}
			}
		mi1,mi2,mx1=INT_MIN,mx2=INT_MIN;
		for(int j=i*k;j<min((i+1)*k,n);j++)
		{
			if(dp[j]>=mx1)
				mx1=dp[j],mi1=j;
		}
		for(int j=i*k;j<min((i+1)*k,n);j++)
		{
			if(j!=mi1)
			{
				if(mx2<=dp[j])
					mx2=dp[j],mi2=j;
			}
		}
	}
	ll ans=dp[0];
	for(int i=1;i<n;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;
}
