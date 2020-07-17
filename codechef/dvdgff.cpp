#include<bits/stdc++.h>
using namespace std;
int dp[100];

//top-up dp
int total_way(int *arr,int n,int p)
{
	if(p==0) return dp[0]=1;
	if(p<0) return 0;
	if(dp[p]!=0) return dp[p];
	int way=INT_MAX;
	for(int i=0;i<n;i++)
	way=min(way,total_way(arr,n,p-arr[i])+1);
	return dp[p]=way;
}

//Bottom-up dp
int total_wayb(int *arr,int n,int p)
{
	if(n==0||p==0) return 0;
	int dpp[p+1]={0};
	for(int i=0;i<n;i++)
	dpp[i]=1;
	for(int i=1;i<=p;i++)
	{
		if(dpp[i]==0)
		{
			int mn=INT_MAX;
			for(int j=0;j<n;j++)
			{
				mn=min(mn,dpp[i-arr[j]]);
			}
			dpp[i]=mn+1;
		}
	}
	for(int i=0;i<=p;i++) cout<<dpp[i]<<" ";
	cout<<endl;
	return dpp[p];
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
