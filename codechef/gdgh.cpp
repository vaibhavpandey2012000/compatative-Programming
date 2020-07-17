#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
void dfs(int nn,int pp)
{
	cout<<nn<<" ";
	for(int ee:arr[nn])
	{
		if(ee!=pp)
		dfs(ee,nn);
	}
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	cin>>a>>b, arr[a].push_back(b),arr[b].push_back(a);
	dfs(1,-1);
}
