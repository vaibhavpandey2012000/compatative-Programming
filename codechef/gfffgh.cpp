#include<bits/stdc++.h>
using namespace std;
const int maxN=10;
vector<int> arr[maxN];
int level[maxN],par[maxN];
int LCA[1001][maxN];
void dfs(int n,int p)
{
	LCA[n][0]=p;
	par[n]=p;
	for(auto e:arr[n])
	{
		if(e!=p)
		{
			dfs(e,n);
			level[e]=level[n]+1;
		}
	}
}
void init(int v)
{
	dfs(1,-1);
	int rr=sqrt(v)+1;
	for(int j=1;j<=maxN;j++)
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
	if(level[a]>level[b]) swap(a,b);
	int d=level[b]-level[a];
	while(d>0)
	{
		int i=log2(d);
		b=LCA[b][i];
		d=d-(1<<i);
	}
	cout<<a<<" "<<b<<endl;
	if(a==b) return a;
	while(par[a]!=par[b])
	a=par[a],b=par[b];
	
	return par[a];
}
int main()
{	
	
	int v,e,a,b;
	cin>>v>>e;
	for(int i=1;i<=v;i++)
	{
		for(int j=0;j<=maxN;j++)
		{
			LCA[i][j]=-1;
		}
	}
	
	for(int i=0;i<e;i++)
	cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(b);
	init(v);
	int x,y;
	cin>>x>>y;
	cout<<lca(x,y)<<endl;
}
