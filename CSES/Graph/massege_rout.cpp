#include<bits/stdc++.h>
using namespace std;
const int maxN=100001;
vector<int> arr[maxN];
int vis[maxN],dis[maxN],par[maxN];
void BFS(int src)
{
	queue<int> q;
	q.push(src);
	vis[src]=1;
	dis[src]=0;
	par[src]=-1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto ch:arr[node])
		{
			if(vis[ch]==0)
			{
				vis[ch]=1;
				dis[ch]=dis[node]+1;
				par[ch]=node;
				q.push(ch);
			}
		}
	}
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=1;i<=v;i++) dis[i]=-1;
	for(int i=0;i<e;i++)
	cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
	
	BFS(1);
	
	if(dis[v]==-1) cout<<"IMPOSSIBLE"<<endl;
	else{
		 cout<<dis[v]+1<<endl;
		 int pr=v;
		 vector<int> vv;
		 while(pr !=-1)
		 {
		 	vv.push_back(pr);
		 	pr=par[pr];
		 }
		 for(int i=vv.size()-1;i>=0;i--)
		 cout<<vv[i]<<" ";
	} 
	
}