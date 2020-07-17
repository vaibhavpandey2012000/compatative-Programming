#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
 const int N= 1e3 ,M=N;

vi g[N];
int dp[N],a[N];
int n;
void dfs(int u,int par)
{
	dp[u]=a[u];
	int mx=0;
	for(int ch:g[u])
	{
		if(ch==par) continue;
		dfs(ch,u);
		mx=max(mx,dp[ch]);
	}
	dp[u]+=mx;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	cout<<dp[1]<<endl;
}