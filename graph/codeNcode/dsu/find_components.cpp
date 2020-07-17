#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;
int parent[maxN];
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
int  main()
{
	int  n,e,a,b;
	cin>>n>>e;
	for(int i=1;i<=n;i++)
		parent[i]=-1;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		a=find(a);
		b=find(b);

		if(a!=b) unioon(a,b);
	}
	for(int i=1;i<=n;i++)
	{
		if(parent[i]<0)
			cout<<i<<"-->"<<abs(parent[i])<<endl;
	}

}