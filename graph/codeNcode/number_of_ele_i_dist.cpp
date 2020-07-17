#include<bits/stdc++.h>
using namespace std;
const int maxN=1000001;
vector<int> arr[maxN];
int vis[maxN],dist[maxN],level[maxN];
int bfs(int n)
{
	queue<int> q;
	q.push(n);
	vis[n]=1;
	dist[n]=0;
	level[dist[n]]++;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto e:arr[node])
			if(vis[e]==0)
			{
				vis[e]=1;
				dist[e]=dist[node]+1;
				level[dist[e]]++;
				q.push(e);
			}

	}
}
int main()
{
	int q,v,e,a,b,n,d;
	cin>>v>>e;
	while(e--)
		cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);

	cin>>q;
	while(q--)
	{
		cin>>n>>d;
		for(int i=0;i<v;i++) vis[i]=0 ,dist[i]=0;
		bfs(n);
	    cout<<level[d]<<endl;
	}

}