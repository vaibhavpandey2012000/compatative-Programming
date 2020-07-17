#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
const int maxN=100005;
vector<int> arr[maxN];
int vis[maxN];
int size_cc;
void dfs(int v)
{
	size_cc++;
	vis[v]=1;
	for(auto e:arr[v])
	{
		if(vis[e]==0)
			dfs(e);
	}
}

int main()
{
	int t,n,e,a,b;
	cin>>t;
	while(t--){
		cin>>n>>e;
		for(int i=0;i<=n;i++) vis[i]=0 ,arr[i].clear();
		for(int i=0;i<e;i++)
			cin>>a>>b ,arr[a].push_back(b) ,arr[b].push_back(a);

		int cc=0;
		int pnc=1;
		for(int i=1;i<=n;i++)
			if(vis[i]==0)
			{
				 cc++;
				 size_cc=0;
				 dfs(i);
				 pnc=(pnc*size_cc)%MOD;
			}
		cout<<cc<<" "<<pnc<<endl;

	}

}