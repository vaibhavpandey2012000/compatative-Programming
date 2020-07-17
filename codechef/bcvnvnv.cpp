#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int>arr[maxN];
int vis[maxN];
int DFS(int src,int par)
{
	vis[src]=1;
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		return DFS(e,src);
		else if(vis[e]==1 && e!=par)
		return 1;
	}
	return 0;
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
		arr[i].clear(),vis[i]=0;
		for(int i=0;i<e;i++)
		cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
		int ppp=0;
		for(int i=1;i<=v;i++)
		{
			if(vis[i]==0){
				ppp=DFS(i,-1);
				if(ppp==1)
				{
					cout<<"NO"<<endl;
					break;
				 } 
			}
			
		}
		if(ppp==0)
		cout<<"YES"<<endl;
	}
}
