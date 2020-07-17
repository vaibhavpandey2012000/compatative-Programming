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
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	vector<int> dist(v+1,inf);
	
	pq.push({0,3});
	dist[3]=0;
	while(!pq.empty())
	{
		int curr=pq.top().second;
		int curr_d=pq.top().first;
		pq.pop();
		
		for(auto edge:arr[curr])
		{
			if(curr_d+edge.second<dist[edge.first])
			{
				dist[edge.first]=curr_d+edge.second;
				pq.push({dist[edge.first],edge.first});
			}
		}
	}
	for(int i=1;i<=v;i++)
	cout<<i<<"--> "<<dist[i]<<endl;
}