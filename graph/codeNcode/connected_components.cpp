#include<bits/stdc++.h>
using namespace std;
const int maxN=200005;
vector<int>arr[maxN];
int vis[maxN];
void DFS(int src)
{
	vis[src]=1;
	//cout<<src<<",";
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		DFS(e);
	}
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,a,b;
		cin>>n>>m;
		for(int i=0;i<=n;i++) arr[i].clear(),vis[i]=0;
		for(int i=0;i<m;i++)
		cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0) DFS(i),cnt++;
		}
		cout<<cnt<<endl;
	}
	
}