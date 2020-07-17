#include<bits/stdc++.h>
using namespace std;
int dp[100];

//top-up dp
int total_way(int *arr,int n,int p)
{
	if(p==0) return dp[0]=1;
	if(p<0) return 0;
	if(dp[p]!=0) return dp[p];
	int way=0;
	for(int i=0;i<n;i++)
	way+=(total_way(arr,n,p-arr[i]));
	return dp[p]=way;
}

//Bottom-up dp
int total_wayb(int *arr,int n,int p)
{
	if(p==0||n==0) return 0;
	int dpp[p+1]={0};
	dpp[0]=1;
	for(int i=1;i<=p;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i-arr[j]>=0)
			dpp[i]+=dpp[i-arr[j]];
		}
	}
	for(int i=0;i<=p;i++)
	cout<<dpp[i]<<" ";
	cout<<endl;
	return dp[p];
}
int main()
{
	int n,p;
	cin>>n>>p;
	int *arr=new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int ans=total_way(arr,n,p);
	int ans1=total_wayb(arr,n,p);
	for(int i=0;i<=p;i++)
	cout<<dp[i]<<" ";
	cout<<endl;
	cout<<ans<<" "<<ans1<<endl;
}