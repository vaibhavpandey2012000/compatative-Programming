#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rodcut(int *arr,int n)
{
	if(n<=0)
	return 0;
	ll ans=INT_MIN;
	for(int i=0;i<n;i++)
	{
		ans=max(
		ans,arr[i]+rodcut(arr,n-i-1));
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	ll ans=rodcut(arr,n);
	cout<<ans<<endl;
}
