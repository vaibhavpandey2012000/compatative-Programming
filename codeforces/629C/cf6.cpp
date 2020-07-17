#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Max=2e5;
int a[Max],b[Max];
ll ans=1e18;
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		b[i+1]=b[i]+a[i];
	}
	for(int i=0,j=0;i<n;i=j)
	{
		for(;j<n && a[j]==a[i];++j);
		ll c=j-i;
		ll x=a[i];
		ll cl=i*(x-1)-b[i];
		ll cr=b[n]-b[j]-(n-j)*(x+1);
		if(c>=k) ans=0;
		if(c+i>=k) ans=min(cl+k-c,ans);
		if(c+n-j>=k) ans=min(cr+k-c,ans);
		ans=min(cl+cr+k-c,ans);
	}
	cout<<max(ans,0ll)<<endl;
}