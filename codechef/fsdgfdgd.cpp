#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,k;
	cin>>n>>k;
	bool arr[n];
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	ll dp[n+1];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=0;
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0 && arr[i]==false)
			dp[i]+=dp[i-j];
		}
	}
//	for(int i=1;i<=n;i++)
//	cout<<dp[i]<<" ";
//	cout<<endl;
	cout<<dp[n]<<endl;
		
} 
