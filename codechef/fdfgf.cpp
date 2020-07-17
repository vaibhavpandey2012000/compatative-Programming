#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int dp[maxn]={0};
int fxn(int n,int k,int *arr)
{
	if(n==0) return 1;
	if(dp[n]!=0) return dp[n];
	int ans;
	for(int i=0;i<k;i++)
	{
		if(n-arr[i]>=0)
		{
			ans+=fxn(n-arr[i],k,arr);
		}
	}
	return dp[n]=ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int arr[k];
	for(int i=0;i<k;i++) cin>>arr[i];
	int ans=fxn(n,k,arr);
	cout<<ans<<endl;
}
