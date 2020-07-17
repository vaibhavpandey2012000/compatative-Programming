#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;
vector<int>arr[maxN];
bool visit[maxN];
int dist[maxN];
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	visit[s]=1;
	dist[s]=0;
	while(!q.empty())
	{
		int node=q.front();
		//cout<<node<<"-->";
		q.pop();
		for(auto ele:arr[node])
			if(visit[ele]==false)
			{
				visit[ele]=true;
				dist[ele]=dist[node]+1;
				q.push(ele);
			}
	}
	cout<<endl;
}
int main()
{
	int t,v,e,a,b;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		cin>>v>>e;

		for(int i=0;i<=v;i++) arr[i].clear() , visit[i]=0 , dist[i]=0;

		while(e--) cin>>a>>b , arr[a].push_back(b) , arr[b].push_back(a);

		int src;

		cin>>src;

		bfs(src);

		for(int i=1;i<=v;i++)
			cout<<dist[i]<<" ";
			cout<<endl;
	}
}