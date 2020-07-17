#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
class Edge{
	public:
		int s,e,w;
};
int parent[maxN];
Edge edge[maxN];
bool comp(Edge e1,Edge e2)
{
	return e1.w<e2.w;
}
int find(int a)
{
	if(parent[a]<0)
		return a;
	else
		find(parent[a]);
}

void unioon(int a,int b)
{
	parent[a]+=parent[b];
	parent[b]=a;
}
vector<Edge> vp;
int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=0;i<=v;i++) parent[i]=-1;
	for(int i=0;i<e;i++)
	cin>>edge[i].s>>edge[i].e>>edge[i].w;
	
	sort(edge,edge+e,comp);
	
	int weight=0;
	for(int i=0;i<e;i++)
	{
		int e1=edge[i].s,e2=edge[i].e,ww=edge[i].w;
		int a=find(e1),b=find(e2);
		if(a!=b)
		{
			vp.push_back({e1,e2,ww});
			weight+=ww;
			unioon(a,b);
		}
	}
	cout<<weight<<endl;
	for(int i=0;i<vp.size();i++)
	cout<<vp[i].s<<" "<<vp[i].e<<" "<<vp[i].w<<endl;
}