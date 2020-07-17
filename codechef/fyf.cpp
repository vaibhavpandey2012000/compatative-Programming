#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN=100005;
int arr[maxN]={0,};
ll ladder(int n,int k)
{
	if(n==0) return 1;
	if(arr[n]!=0) return arr[n];
	ll wayes=0;
	for(int i=1;i<=k;i++)
	if(n-i>=0)
	wayes+=ladder(n-i,k);
	return arr[n]=wayes;
}
ll ladder_bottom(int n,int k)
{
	int dp[n+1];
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		for(int j=1;j<=k;j++)
		if(i-j>=0)
		dp[i]+=dp[i-j];
	}
	return dp[n];
}
int main()
{
	int n,k;
	cin>>n>>k;
	ll ans=ladder(n,k);
	ll ans2=ladder_bottom(n,k);
	cout<<ans<<" "<<ans2<<endl;
}
