#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;

struct edge{
	int a,b,w;
};
edge ar[maxN*10];
int parent[maxN];

bool comp(edge a,edge b)
{
	return a.w<b.w;
}

int find(int a)
{
	if(parent[a]<0)
		return a;

	return parent[a]=find(parent[a]);
}

void merge(int a,int b)
{
	parent[a]=b;
}

int main()
{
	int m,e,a,b,w;
	cin>>m>>e;
	for(int i=1;i<=m;i++) parent[i]=-1; 

	for(int i=0;i<e;i++)
		cin>>ar[i].a>>ar[i].b>>ar[i].w;

	sort(ar,ar+e,comp);

	vector<edge> v;
	int sum=0;
	for(int i=0;i<e;i++)
	{
		int t1=ar[i].a ,t2=ar[i].b ,t3=ar[i].w;
		a=find(ar[i].a);
		b=find(ar[i].b);

		if(a!=b) {
			merge(a,b);
			sum+=ar[i].w;
			v.push_back({t1,t2,t3});
		}
	}

	cout<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].w<<endl;
	}

	cout<<sum<<endl;
}
