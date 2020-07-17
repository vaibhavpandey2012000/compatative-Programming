#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+5;
vector<int> arr[maxN];
int vis[maxN];
int color[maxN];
bool DFS(int src,int c)
{
	color[src]=c;
	vis[src]=1;
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		{
			return DFS(e,c^1);
		}
		else if(color[src]==color[e])
		return false;
	}
	return true;
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
		arr[v].clear(),vis[i]=0;
		for(int i=0;i<e;i++)
		cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
		bool cc=DFS(1,0);
		if(cc) cout<<"BiPartite"<<endl;
		else cout<<"Not BiPartite"<<endl;
	}
	
}
