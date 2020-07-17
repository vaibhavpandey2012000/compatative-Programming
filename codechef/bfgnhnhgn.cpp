#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int maxN=100005;
vector<int>arr[maxN];
int vis[maxN],dis[maxN];
int com=0;
void DFS(int src,int d)
{
	dis[src]=d;
	vis[src]=1;
	com=(com++)%MOD;
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		DFS(e,d+1);
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
		for(int i=0;i<=v;i++)
		arr[i].clear(),vis[i]=0,dis[i]=0;
		for(int i=0;i<e;i++)
		cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
		int cc=0,ans=1;
		for(int i=1;i<=v;i++)
		{
			if(vis[i]==0)
			{
				com=0;
				cc++;
				DFS(i,-1);
				ans=(ans*com)%MOD;
			}
		}
		cout<<cc<<" "<<ans<<endl;
	}
}
