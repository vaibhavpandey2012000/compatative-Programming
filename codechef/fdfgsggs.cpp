#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int sbsiz[maxN],vis[maxN];
int dfs(int s)
{
	vis[s]=1;
	int cc=1;
	for(auto e:arr[s])
	{
		if(vis[e]==0)
		{
			cc+=dfs(e);
		}
	}
	sbsiz[s]=cc;
	return cc;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int v,e,a,b;
		cin>>v>>e;
		for(int i=1;i<=v;i++)
		arr[i].clear(),vis[i]=0,sbsiz[i]=0;
		for(int i=0;i<e;i++)
		cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);
		int cd=dfs(1);
		for(int i=1;i<=v;i++)
		cout<<sbsiz[i]<<" ";
	}
}
