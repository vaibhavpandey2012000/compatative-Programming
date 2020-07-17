#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;
int par[maxN],Rank[maxN];
int find(int a)
{
	if(par[a]<0)
		return a;
	return par[a]=find(par[a]);
}
void unioon(int a,int b)
{
	a=find(a);
	b=find(b);

	if(a==b) return;

	if(Rank[a]>Rank[b])
		par[b]=a ,Rank[a]+=Rank[b];
	else
		par[a]=b ,Rank[b]+=Rank[a];
}
int main()
{
	int n,e,a,b;
	cin>>n>>e;
	for(int i=0;i<e;i++)
		par[i]=-1 , Rank[i]=1;

	for(int i=0;i<e;i++)
		cin>>a>>b , unioon(a,b);

	for(int i=1;i<=n;i++)
		cout<<par[i]<<" ";
	
	
}