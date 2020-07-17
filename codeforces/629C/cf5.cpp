#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int mxN=2e5;
int n,m,d[mxN],anc[mxN][18];
class graph{
	int v;
	list<int> *adj;
	public:
		graph(int v)
		{
			this->v=v;
			adj=new list<int>[v+1];
		}
		void addedge(int a,int b)
		{
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int lca(int u,int v)
		{
			if(d[u]<d[v])
		 	    swap(u,v);
			for(int i=17;i>=0;i--)
			    if(d[u]-(1<<i)>=d[v])
 					 u=anc[u][i];
		    if(u==v)
    		  return u;
	  	    for(int i=17;i>=0;--i)
 	    		if(anc[u][i]^anc[v][i])
			      u=anc[u][i],v=anc[v][i];
	        return anc[u][0];
		}
		void dfs(int u=0,int p=-1)
		{
			anc[u][0]=p;
			for(int i=1;i<18;++i)
			    anc[u][i]=~anc[u][i-1]? anc[anc[u][i-1]][i-1]:-1;
			for(int v:adj[u])
			{
				if(v^p){
					d[v]=d[u]+1;
					dfs(v,u);
				}
			}
		}
};
int main()
{
	int n,m;
	cin>>n>>m;
	graph g(n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		g.addedge(a,b);
	}
	g.dfs();
	while(m--)
	{
		int k;
		cin>>k;
		vector<int> v(k);
		for(int i=0;i<k;++i)
		{
			cin>>v[i];
			--v[i];
		}
		sort(v.begin(),v.end(),[](const int &i,const int &j){
			return d[i]<d[j];
		});
		bool ok=1;
		for(int i=0;i<k-1 && ok;i++)
		{
			int w=g.lca(v[i],v[k-1]);
			ok=d[v[i]]<=d[w]+1;
			// if(!ok)
			// cout<<v[i]<<endl;
		}
		cout<<(ok?"YES":"NO")<<"\n";
	}
} 