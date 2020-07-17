#include<bits/stdc++.h>
using namespace std;
int binerystring(int n,int last_dig)
{
	//string s="";
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		if(last_dig)
		return 1;
		else
		return 2;
	}
	if(last_dig)
	return binerystring(n-1,0);
	else
	return binerystring(n-1,0)+binerystring(n-1,1);
}
// DP solution topup
/*

int dp[MX][2]={0};
int binerystring(int n,int last_dig)
{
	if(n==0)
	return 0;
	dp[1][0]=2;
	dp[1][1]=1;
	if(dp[n][last_dig]!=0)
	return dp[n][last_dig];
	if(last_dig)
	return binerystring(n-1,0);
	else
	return binerystring(n-1,0)+binerystring(n-1,1);
}


*/

// DP Bottomup
/*
long long binerystring(int n,int p)
{
	dp[mx]=0;
	dp[0]=0;
	dp[1]=2;
	dp[2]=3;
	for(int i=3;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<dp[n]<<endl;
}
*/
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int p=binerystring(n,0);
		cout<<p<<endl;
	}
}