#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int fee=arr[0];
	int dp[n]={0};
	dp[0]=arr[0];
	dp[1]=arr[1];
	for(int i=2;i<n;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2])+arr[i];	
	}
	for(int i=0;i<n;i++)
	cout<<dp[i]<<" ";
	cout<<endl;
	cout<<fee<<endl;
}
