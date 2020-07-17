#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;
vector<int> arr[maxN];
int vis[maxN];
int subtree[maxN];
int dfs(int v)
{
	vis[v]=true;
	int curr_size=1;

	for(auto e:arr[v])
	{
		if(vis[e]==0)
			curr_size+=dfs(e);
	}
	subtree[v]=curr_size;
	return curr_size;
}
int main()
{
	int n,a,b,k;
	cin>>n;

	for(int i=0;i<(n-1);i++)
		cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);

	cin>>k;
	int kk=dfs(k);
	for(int i=1;i<=n;i++)
	{
		cout<<subtree[i]<<" ";
	}
}