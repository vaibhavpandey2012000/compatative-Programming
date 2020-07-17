#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long arr[n];
	long long pre[n],suf[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	pre[0]=arr[0];
	suf[n-1]=arr[n-1];
	for(int i=1;i<n;i++)
	pre[i]=max(pre[i-1],(arr[i]));
	for(int i=n-2;i>=0;i--)
	suf[i]=max(suf[i+1],arr[i]);
//	for(int i=0;i<n;i++) cout<<pre[i]<<" ";
//	cout<<endl;
//	for(int i=0;i<n;i++) cout<<suf[i]<<" ";
//	cout<<endl;
	long long ans=0;
	for(int i=0;i<n;i++)
	ans+=min(pre[i],suf[i])-arr[i];
	cout<<ans<<endl;
}
