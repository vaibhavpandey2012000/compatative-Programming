#include<bits/stdc++.h>
using namespace std;
const int maxN=10;//10 is sqrt of 101
vector<int>arr[101];
int LCA[101][maxN];
int level[101];
void dfs(int n,int p)
{
	LCA[n][0]=p;
	for(auto e:arr[n])
	{
		if(e!=p)
		{
			level[e]=level[n]+1;
			dfs(e,n);
		}
	}
}
void init(int v)
{
	dfs(1,-1);
	for(int j=1;j<=log2(v);j++)
	{
		for(int i=1;i<=v;i++)
		{
			if(LCA[i][j-1]!=-1){
				int par=LCA[i][j-1];
				LCA[i][j]=LCA[par][j-1];
			}
		}
	}
}
int lca(int a,int b)
{
	if(level[b]<level[a]) swap(a,b);
	int d=level[b]-level[a];
	while(d)
	{
		int i=log2(d);
		b=LCA[b][i];
		d-=(1<<i);
	}
	if(a==b) return a;
	for(int i=maxN-1;i>=0;i--)
	{
		if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
		a=LCA[a][i],b=LCA[b][i];
	}
	return LCA[a][0];
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=1;i<=v;i++)
	for(int j=0;j<maxN;j++)
	LCA[i][j]=-1;
	for(int i=0;i<e;i++)
	cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
	init(v);
	int x,y;
	cin>>x>>y;
	cout<<lca(x,y)<<endl;
}