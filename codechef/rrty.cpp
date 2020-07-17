#include<bits/stdc++.h>
using namespace std;
const int maxN=100001;
vector<int> arr[maxN];
int vis[maxN],clr[maxN];
bool dfs(int src,int c)
{
	vis[src]=1;
	clr[src]=c;
	cout<<src<<endl;
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		{
			return dfs(e,1^c);
		}
		else if( clr[e]==clr[src])
		return false;
	}
	return true;
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=1;i<=v;i++) clr[i]=-1;
	for(int i=0;i<e;i++)
	cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
	
	bool ans=dfs(1,0);
	if(ans)
	{
		for(int i=1;i<=v;i++)
		cout<<clr[i]+1<<" ";
	}
	else
	cout<<"IMPOSSIBLE"<<endl;
	
}
