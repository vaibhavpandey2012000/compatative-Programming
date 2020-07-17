#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int vis[maxN];
int in[maxN],out[maxN];
int t=1;
void dfs(int src,int p)
{
	in[src]=t++;
	vis[src]=1;
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		dfs(e,src);
	}
	out[src]=t++;
}
int main()
{
	int  tc;
	cin>>tc;
	while(tc--)
	{
		int v,e,a,b;
		cin>>v>>e;
		for(int i=1;i<=v;i++)
		arr[i].clear(),vis[i]=0;
		for(int i=0;i<e;i++)
		cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);
		dfs(1,-1);


		for(int i=1;i<=v;i++)
		cout<<in[i]<<" ";
		cout<<endl;
		for(int i=1;i<=v;i++)
		cout<<out[i]<<" ";
		cout<<endl;


		cout<<"Number of leaf:";
		for(int i=1;i<=v;i++)
		if(in[i]==out[i]-1)
		cout<<i<<" ";
		cout<<endl;

		
		cout<<"Number of subtree:"<<endl;
		for(int i=1;i<=v;i++)
		cout<<i<<"-->"<<(out[i]-in[i]+1)/2<<endl;
	}
}