#include<bits/stdc++.h>
using namespace std;
const int maxN=100001;
vector<int> arr[maxN];
int vis[maxN],color[maxN];
bool bfs()
{
	queue<int> q;
	q.push(1);
	color[1]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto e:arr[node])
		{
			if(color[e]==-1){
				color[e]=1-color[node];
				q.push(e);
			}
			
			else if(color[e]==color[node])
			return 0;
		}
	}
	return 1;
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=1;i<=v;i++) color[i]=-1;
	for(int i=0;i<e;i++)
	cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
	
	bool ans=bfs();
	if(ans)
	{
		for(int i=1;i<=v;i++)
		if(color[i]==-1) cout<<"1 ";
		else
		cout<<color[i]+1<<" ";
	}
	else
	cout<<"IMPOSSIBLE"<<endl;
	
}