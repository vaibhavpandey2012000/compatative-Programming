#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int level[maxN],par[maxN],vis[maxN];
void dfs(int n,int p)
{
	vis[n]=1;
	par[n]=p;
	for(auto e:arr[n])
	{
		if(vis[e]==0)
		{
			level[e]=level[n]+1;
			dfs(e,n);
		}
	}
}
//nive approch to find lca
int lca(int a,int b)
{
	int d=level[b]-level[a];
	if(d<0) d*=-1,swap(a,b);
	while(d>0)
	{
		b=par[b];
		d--;
	}
	if(b==a) return a;
	while(par[a]!=par[b])
	a=par[a],b=par[b];
	return par[a];
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(b);
	dfs(1,-1);
	int x,y;
	cin>>x>>y;
	cout<<lca(x,y)<<endl;
}
