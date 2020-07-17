#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int visit[maxN],comp[maxN];
int cc=0;
void dfs(int s,int e)
{
	comp[s]=1;
	for(auto ch:arr[s])
	{
		if(ch==e)
		continue;
		dfs(ch,s);
		comp[s]+=comp[ch];
	}
}
int ans=0;

int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++)
		cin>>a>>b , arr[a].push_back(b) , arr[b].push_back(a);
	dfs(1,0);
//	for(int i=1;i<=v;i++)
//		cout<<i<<"-->"<<comp[i]<<" "<<endl;
	for(int i=1;i<=v;i++)
	{
		if(comp[i]%2==0)
		ans++;
	}
	cout<<ans-1<<endl;
	
}