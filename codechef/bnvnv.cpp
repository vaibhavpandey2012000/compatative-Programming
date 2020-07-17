#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int vis[maxN],in[maxN],low[maxN];
set<int>s;
int timer=0;
void DFS(int node,int par)
{
	vis[node]=1;
	in[node]=low[node]=timer;
	timer++;
	int child_cnt=0;
	for(auto child:arr[node])
	{
		if(child==par) continue;
		else if(vis[child]==1)
		{
			low[node]=min(low[node],in[child]);
		}
		else{
			DFS(child,node);
			child_cnt++;
			low[node]=min(low[child],low[node]);
			if(in[node]<=low[child] && par!=-1)
			s.insert(node);
		}
	}
	if(child_cnt>1 && par==-1)
	s.insert(node);
}
int main()
{
	while(1)
	{
		int n,m,a,b;
		cin>>n>>m;
		if(n==0 && m==0) break;
		for(int i=1;i<=n;i++)
		arr[i].clear() ,vis[i]=0;
		s.clear();
		for(int i=0;i<m;i++)
		cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);
		
		for(int i=1;i<=n;i++)
		DFS(i,-1);
		
		cout<<s.size()<<endl;
//		for(auto e:s) cout<<e<<" ";
//		cout<<endl;
	}
}
