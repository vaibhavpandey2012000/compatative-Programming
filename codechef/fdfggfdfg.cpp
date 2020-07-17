#include<bits/stdc++.h>
using namespace std;
const int maxN=100001;
vector<int> arr[maxN];
int vis[maxN],in[maxN],low[maxN];
int timer=0;

void dfs(int src,int par)
{
	vis[src]=1;
	in[src]=low[src]=timer;
	timer++;
	for(int ch:arr[src])
	{
		if(ch==par) continue;
		else if(vis[ch])
		low[src]=min(low[src],in[ch]);
		else if(vis[ch]==0)
		{
			dfs(ch,src);
			if(low[ch]>in[src])
			cout<<src<<"--"<<ch<<"is a bridge"<<endl;
			low[src]=min(low[src],low[ch]);
		}
	}
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++) 
	cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);
	
	dfs(1,-1);
}
