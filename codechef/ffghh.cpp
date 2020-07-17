#include<bits/stdc++.h>
using namespace std;
const int maxN=100001;
vector<int> arr[maxN];
int vis[maxN],in[maxN],low[maxN];
int timer=0;
void DFS(int node,int pr)
{
	vis[node]=1;
	in[node]=low[node]=timer;
	timer++;
	for(auto child:arr[node])
	{
		if(child==pr) continue;
		if(vis[child]==1)
		low[node]=min(low[node],in[child]);
		else
		{
			DFS(child,node);
			if(low[child]>in[node])
			cout<<node<<"--"<<child<<endl;
		}
	}
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
	
	DFS(1,-1);
}
