#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
vector<int> leaf;
int visited[maxN];
int timer=0,parent[maxN];
int cmpo[maxN];
void dfs(int node,int par)
{
	timer++;
	visited[node]=1;
	int flg=1;
	int p=timer;
	for(auto ch: arr[node])
	{
		if(!visited[ch])
		{
			dfs(ch,node);
			flg=0;
		}
	}
	timer++;
	if(flg==1){
		cmpo[node]=1;
		leaf.push_back(node);	
	}
	else
		cmpo[node]=(timer-p+1)/2;
}
int main()
{
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++)
		cin>>a>>b , arr[a].push_back(b) ,arr[b].push_back(a);
	
	dfs(1,-1);
	//leaf node
	for(auto l:leaf)
		cout<<l<<" ";
	cout<<endl;
	//number of components
	for(int i=1;i<=v;i++)
		cout<<i<<"-->"<<cmpo[i]<<" ";
	
}