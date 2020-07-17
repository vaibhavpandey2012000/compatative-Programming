#include<bits/stdc++.h>
using namespace std;
// lca for o(n)
vector<int> arr[1001];
const int maxN=10;
int level[1001],LCA[1001][maxN];

void dfs(int v,int l,int p)
{
	level[v]=l;
	LCA[v][0]=p;
	for(auto c:arr[v])
	{
		if(c!=p)
		dfs(c,l+1,v);
	}
	
}
void init(int n)
{
	dfs(1,0,-1);
	for(int i=1;i<=maxN;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(LCA[j][i-1]!=-1)
			{
				int par=LCA[j][i-1];
				LCA[j][i]=LCA[par][i-1];
			}
		}
	}
}

int getLCA(int a,int b)
{
	if(level[b]<level[a]) swap(a,b);
	int d=level[b]-level[a];
	while(d)
	{
		int i=log2(d);
		b=LCA[b][i];
		d-=(1 << i);
	}
	if(a==b) return b;
	for(int i=maxN ;i>=0;i--)
	{
		if(LCA[a][i]!= -1 && (LCA[a][i]!=LCA[b][i]))
		{
			a=LCA[a][i];
			b=LCA[b][i];
		}
	}
	return LCA[a][0];
}

int getdistance(int a,int b)
{
	int lca=getLCA(a,b);
	return level[a]+level[b]-2*level[lca];
}
int main()
{
	int n,a,b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=maxN;j++)
		{
			LCA[i][j]=-1;
		}
	}
	
	for(int i=1;i<n;i++)
		cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);
		
	init(n);
	
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		cout<<getdistance(a,b)<<endl;
	}
}