#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int vis[maxN],dis[maxN];
void BFS(int s)
{
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		cout<<node<<"-->";
		for(auto e:arr[node])
		{
			if(vis[e]==0)
			{
				vis[e]=1;
				dis[e]=dis[node]+1;
				q.push(e);
			}
		}
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
		for(int i=1;i<=v;i++)
		arr[i].clear(),vis[i]=0,dis[i]=0;
		for(int i=0;i<e;i++)
		cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
		BFS(1);
		cout<<endl;
		for(int i=1;i<=v;i++)
		cout<<dis[i]<<" ";
	}
}
