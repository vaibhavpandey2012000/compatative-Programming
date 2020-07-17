#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int>arr[maxN];
int vis[maxN],dis[maxN];
void DFS(int src,int d)
{
	dis[src]=d;
	vis[src]=1;
	cout<<src<<" ";
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		DFS(e,d+1);
	}
}
void show(int v)
{
	for(int i=1;i<v;i++)
	{
		cout<<i<<"-->";
		for(auto e:arr[i])
		cout<<e<<" ,";
		cout<<endl;
	}
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int v,e,a,b;
		cin>>v>>e;
		for(int i=0;i<=v;i++)
		arr[i].clear(),vis[i]=0,dis[i]=0;
		for(int i=0;i<e;i++)
		cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
		show(v);
		int src;
		cin>>src;
		DFS(src,0);
		cout<<endl;
		for(int i=1;i<=v;i++)
		cout<<dis[i]<<" ";
		cout<<endl;
	}
}
