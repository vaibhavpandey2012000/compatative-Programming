#include<bits/stdc++.h>
using namespace std;
const int maxN=100;
int arr[maxN];
int ladder_topup(int n,int k,int *dp)
{
	if(n==0) return 1;
	if(dp[n]!=0) return dp[n];
	int wayes=0;
	for(int i=1;i<=k;i++)
	if(n-i>=0)
	wayes+=ladder_topup(n-i,k,dp);
	return dp[n]=wayes;
}
int ladder_bottom(int n,int k)
{
	arr[0]=1;
	for(int i=1;i<=n;i++)
	{
		arr[i]=0;
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
			arr[i]+=arr[i-j];
		}
	}
	return arr[n];
}
int main()
{
	int n,k;
	int dp[n+5]={0};
	cin>>n>>k;
	int ans=ladder_topup(n,k,dp);
	int ans1=ladder_bottom(n,k);
	cout<<ans<<" "<<ans1<<endl;
}
