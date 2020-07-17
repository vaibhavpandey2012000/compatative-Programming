#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int visit[maxN],in[maxN],low[maxN],timer;
bool notok;
vector<pair<int,int> >edge;

void dfs(int node,int par)
{
	visit[node]=1;
	low[node]=in[node]=timer;
	timer++;
	for(auto child:arr[node])
	{
		if(child==par) continue;

		else if(visit[child])
		{
			low[node]=min(low[node],in[child]);
			edge.push_back({node,child});
		}
		else{
			dfs(child,node);
			if(low[child]>in[node])
			{
				notok=true;
				return;
			}
			edge.push_back({node,child});
			low[node]=min(low[node],low[child]);
		}

	}
}

int main()
{
	int m,n,a,b;
	cin>>m>>n;

	for(int i=0;i<n;i++)
		cin>>a>>b , arr[a].push_back(b) , arr[b].push_back(a);

	dfs(1,-1);

	if(notok)
		cout<<"0"<<endl;
	else{
		for(auto e:edge)
			cout<<e.first<<" "<<e.second<<endl;
	}

}