#include<bits/stdc++.h>
using namespace std;
int dp[100]={0,};
//recursion
int fxnR(vector<int> &v,int n)
{
	if(n==0)
		return 0;
	int ans=INT_MAX;
	for(int i=0;i<v.size();i++)
	{   
		int ans1=INT_MAX;
		if((n-v[i])>=0)
		 ans1=fxnR(v,n-v[i])+1;
		 ans=min(ans,ans1);
	}
	return ans;
}
//topup dp
int fxn(vector<int> &v,int n)
{
	if(n==0)
		return 0;
	if(dp[n]!=0)
		return dp[n];
	int ans=INT_MAX;
	for(int i=0;i<v.size();i++)
	{   
		if((n-v[i])>=0){
		int  ans1=fxn(v,n-v[i]);
		 ans=min(ans,ans1+1);	
		}
	}
	return dp[n]=ans;
}
// BottomUp DP
int fxnB(vector<int>&v,int n)
{
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		 dp[i]=INT_MAX;
		for(int j=0;j<v.size();j++)
		{
			if(n-v[j]>=0)
			{
				int ans1=dp[n-v[j]];
				dp[i]=min(dp[i],ans1+1);
			}
		}
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int coin;
	cin>>coin;
	cout<<fxnB(v,coin)<<endl;
}
