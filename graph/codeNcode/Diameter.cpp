
#include<bits/stdc++.h>
using namespace std;
const int maxN=1005;
vector<int> arr[maxN];
int vis[maxN]={0};
int maxd,maxnode;
void dfs(int v,int d)
{
	vis[v]=1;
	if(maxd<d) maxd=d ,maxnode=v;
	for(auto e:arr[v])
		if(vis[e]==0)
			dfs(e,d+1);
	
}
int main()
{
	int n,e,a,b;
	cin>>n;

	for(int i=0;i<(n-1);i++)
		cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);

	maxd=-1;
	dfs(1,0);

	for(int i=0;i<=n;i++) vis[i]=0;
	maxd=-1;
	dfs(maxnode,0);

	cout<<maxnode<<" "<<maxd<<endl;
}