#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[255][50];
ll coin_change(int n,int *arr,int idx,int tt)
{
	if(idx==tt) return 0;
	if(n==0)
	return 1;
	if(n<0)
	return 0;
	if(dp[n][idx]!=0) return dp[n][idx];
	ll a1=coin_change(n-arr[idx],arr,idx,tt);
	ll a2=coin_change(n,arr,idx+1,tt);
	return dp[n][idx]=a1+a2;
}
int main()
{
	int tc;
	int n,m;
	cin>>n>>m;
	int arr[m];
	for(int i=0;i<m;i++)
	cin>>arr[i];
	ll ans=coin_change(n,arr,0,m);
	cout<<ans<<endl;
}
