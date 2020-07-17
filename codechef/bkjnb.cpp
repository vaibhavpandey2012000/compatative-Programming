#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2000005];
ll fun(int n,int k,vector<int>&v)
{
	int flg=1;
	int mx=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		if(v[i]>0)
		flg=0;
		mx=max(mx,v[i]);
	}
	if(flg==1) return 0;
	for(int i=k+1;i<=n;i++)
	{
		for(int j=i/k;j<i/k+k;j++)
		cout<<i<<" "<<j<<endl;
	}
	
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	ll max_sum=fun(n,k,v);
	cout<<max_sum<<endl;
} 
