#include<bits/stdc++.h>
using namespace std;
int dp[100]={0};
//recursive approch
int fxn_r(int n)
{
	if(n==1)
		return 0;
	int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
 	ans1=fxn_r(n-1)+1;
	if(n%2==0)
	{
	 ans2=fxn_r(n/2)+1;
	}
	if(n%3==0)
	{
		ans3=fxn_r(n/3)+1;
	}
	return min(ans1,min(ans2,ans3));
}
//TopUp approch
int  fxn_T(int n)
{
	if(n==1)
		return 0;
	if(dp[n]!=0)
	{
		return dp[n];
	}
	int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
 	ans1=fxn_T(n-1)+1;
	if(n%2==0)
	{
	 ans2=fxn_T(n/2)+1;
	}
	if(n%3==0)
	{
		ans3=fxn_T(n/3)+1;
	}
	return dp[n]= min(ans1,min(ans2,ans3));
}
//BottomUp approch
int fxn(int n)
{
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
		ans1=dp[i-1]+1;
		if(i%2==0)
			ans2=dp[i/2]+1;
		if(i%3==0)
			ans3=dp[i/3]+1;
		dp[i]=min(ans1,min(ans2,ans3));
	}
	return dp[n];
}
//main fxn
int main()
{
	int n;
	cin>>n;
	cout<<fxn(n)<<endl;
}
	