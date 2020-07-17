#include<bits/stdc++.h>
using namespace std;
const int maxN=100001;
vector<int> arr[maxN];
int dis[maxN],vis[maxN];
bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)
	if(n%i==0) return false;
	return true;
}

bool isvalid(int a,int b)
{
	int cnt=0;
	while(a)
	{
		if(a%10!=b%10) cnt++;
		a=a/10 ,b=b/10;
	}
	if(cnt==1) return true;
	else return false;
}

void initgraph()
{
	vector<int> v;
	for(int i=1000;i<=9999;i++)
	if(isprime(i))
	v.push_back(i);
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		if(isvalid(v[i],v[j]))
		arr[v[i]].push_back(v[j]),arr[v[j]].push_back(v[i]);
	}
}
void bfs(int src)
{
	queue<int> q;
	q.push(src);
	vis[src]=1;
	dis[src]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto e:arr[node])
		{
			if(vis[e]==0)
			{
				vis[e]=1;
				dis[e]=dis[node]+1;
				q.push(e);
			}
		}
	}
}
int main()
{
	initgraph();
	int tc;
	cin>>tc;
	while(tc--)
	{
		for(int i=1000;i<=9999;i++)
		dis[i]=-1,vis[i]=0;
		int a,b;
		cin>>a>>b;
		bfs(a);
		if(dis[b]==-1) cout<<"IMPOSSIBLE"<<endl;
		else cout<<dis[b]<<endl;
	}
}
