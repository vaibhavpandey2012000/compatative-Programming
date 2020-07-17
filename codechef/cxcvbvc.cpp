#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
//top up dp
int subsetsum(int *arr,int ind,int n,int s)
{
	if(s==0)
	return 1;
	if(s<0)
	return 0;
	if(dp[ind][s]!=0) return dp[ind][s];
	int ans;
	for(int i=ind;i<n;i++)
	{
		ans=(subsetsum(arr,ind+1,n,s-arr[ind])+subsetsum(arr,ind+1,n,s));
	}
	return dp[ind][s]=ans;
}
//bottom up dp
int btmup(int *arr,int n,int s)
{
	if(s==0||n==0) return 0;
	int dpp[n+1][s+1];
	for(int i=0;i<n;i++) dpp[i][0]=1;
	for(int j=1;j<=s;j++) dpp[0][j]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			int include=0;
			if(j-arr[i-1]>=0)
			include=dpp[i-1][j-arr[i-1]];
			int exclude=dpp[i-1][j];
			dpp[i][j]=include+exclude;
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=s;j++)
		cout<<dpp[i][j]<<" ";
		cout<<endl;
	}
	return dpp[n][s];
}

int main()
{
	int n,s;
	cin>>n>>s;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans1=subsetsum(arr,0,n,s);
	int ans2=btmup(arr,n,s);
	cout<<ans1<<" "<<ans2<<endl;
}
