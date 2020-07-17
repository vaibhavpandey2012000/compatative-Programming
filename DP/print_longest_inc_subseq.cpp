#include<bits/stdc++.h>
using namespace std;
int arr[100],par[100],dp[100];
int longest(int n)
{
	int mx=1;
	par[0]=-1;
	int ind;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
				par[i]=j;
			}
			
		}
		if(mx<dp[i]){
			ind=i;
			mx=dp[i];
		}
	}
	vector<int> v;
	for(int i=0;i<n;i++)
	cout<<par[i]<<" ";
	cout<<endl;
	while(ind!=-1)
	{
		v.push_back(arr[ind]);
		ind=par[ind];
	}
	for(int i=v.size()-1;i>=0;i--)
	cout<<v[i]<<" ";
	cout<<endl;
	return mx;
}
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		dp[i]=1;
		par[i]=-1;
	} 
	par[0]=-1;
	int ans=longest(n);
	cout<<ans<<endl;
}