#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
vector<int> leaf;
void dfs(int node,int par)
{
	int flg=1;
	for(auto child:arr[node])
	{
		if(child!=par)
		{
			flg=0;
			dfs(child,node);
		}
	}
	if(flg)
		leaf.push_back(node);
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++)
		cin>>a>>b , arr[a].push_back(b) ,arr[b].push_back(a);
	
	dfs(1,-1);
	
	for(auto e:leaf)
		cout<<e<<" ";
	
}