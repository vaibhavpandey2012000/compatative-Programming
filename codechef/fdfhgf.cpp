#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
const int maxN=10005;
vector<pair<int,int> >arr[maxN];
int main()
{
	int v,e,a,b,w;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		arr[a].push_back({b,w});
		arr[b].push_back({a,w});
	}
	int s;
	cin>>s;
	vector<int> dist(v+1,inf);
	dist[s]=0;
	set<pair<int,int> >q;
	q.insert({0,s});
	while(!q.empty())
	{
		int vv=q.begin()->second;
		q.erase(q.begin());
		for(auto edge:arr[vv])
		{
			int uu=edge.first;
			int ww=edge.second;
			if(dist[vv]+ww<dist[uu])
			{
				q.erase({dist[uu],uu});
				dist[uu]=dist[vv]+ww;
				q.insert({dist[uu],uu});
			}
		}
	}
	for(int i=1;i<=v;i++)
	cout<<i<<"-->"<<dist[i]<<endl;
}
