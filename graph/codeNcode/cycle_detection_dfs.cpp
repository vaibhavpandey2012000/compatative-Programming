#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int vis[maxN];
bool dfs(int src,int p)
{
	vis[src]=1;
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		return dfs(e,src);
		else if(vis[e]==1 && e!=p)
		return false;
	}
	return true;
}
int main()
{
	int  tc;
	cin>>tc;
	while(tc--)
	{
		int v,e,a,b;
		cin>>v>>e;
		for(int i=1;i<=v;i++)
		arr[i].clear(),vis[i]=0;
		for(int i=0;i<e;i++)
		cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);
		bool ans=dfs(1,-1);
		if(ans)
		cout<<"No cycle"<<endl;
		else
		cout<<"cycle"<<endl;
	}
}