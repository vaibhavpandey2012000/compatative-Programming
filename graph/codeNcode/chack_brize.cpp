#include<bits/stdc++.h>
using namespace std;
const int maxN=1005;
vector<int> arr[maxN];
int vis[maxN],in[maxN],low[maxN];
int timer;

void dfs(int node,int parent)
{
	vis[node]=true;
	in[node]=low[node]=timer;
	timer++;
	for(auto child:arr[node])
	{
		if(child==parent) continue;
		if(vis[child])
		{
			low[node]=min(low[node],in[child]);
		}
		else
		{
			dfs(child,node);
			if(low[child]>in[node])
				cout<<node<<"--"<<child<<" is a brize"<<endl;
			low[node]=min(low[node],low[child]);
		}
	}
}

int main()
{
	int v,e,a,b;
	cin>>v>>e;

	while(e--)
		cin>>a>>b , arr[a].push_back(b) , arr[b].push_back(a);

	dfs(1,-1);
}