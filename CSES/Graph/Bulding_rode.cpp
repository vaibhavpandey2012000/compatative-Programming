#include<bits/stdc++.h>
using namespace std;
const int maxN=100001;
vector<int> arr[maxN];
int vis[maxN];
void DFS(int src)
{
	
	vis[src]=1;
	for(auto e:arr[src])
	{
		if(vis[e]==0)
		DFS(e);
	}
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	cin>>a>>b ,arr[a].push_back(b),arr[b].push_back(a);
	
	int cc=0;
	int prev=1;
	vector<int>d;
	for(int i=1;i<=v;i++)
	{
		if(vis[i]==0){
			DFS(i);
			cc++;
			d.push_back(i);
		}
	}
	cout<<cc-1<<endl;
	for(int i=1;i<d.size();i++)
	cout<<prev<<" "<<d[i]<<endl;
}