#include<bits/stdc++.h>
#define ll long long
#define max(a,b,c) max(a,max(b,c)) 
using namespace std;
int main()
{
	int n;
	cin>>n;
	ll arr[n],dp[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	dp[0]=arr[0];
	dp[1]=arr[1];
	dp[2]=arr[2];
	for(int i=3;i<n;i++)
	dp[i]=arr[i]+max(dp[i-1],dp[i-2],dp[i-3]);
	
	ll ans=max(dp[n-1],dp[n-3],dp[n-3]);
	cout<<ans<<endl;
}
