#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int coin_change(int n,int k,vector<int> &v)
{
	int dp[n+1]={0};
	dp[0]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(i-v[j]>=0)
			dp[i]+=dp[i-v[j]];
		}
	}
	for(int i=0;i<=n;i++)
	cout<<dp[i]<<" ";
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>v(k);
	for(int i=0;i<k;i++) cin>>v[i];
	int sol=coin_change(n,k,v);
	cout<<sol<<endl;
}
