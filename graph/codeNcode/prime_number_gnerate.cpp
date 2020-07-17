#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;
vector<int> arr[maxN];
vector<int> prime;
int dist[maxN];
bool visit[maxN];

bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}


bool isvalid(int a,int b)
{
	int cnt=0;
	while(a>0)
	{
		if(a%10!=b%10)
			cnt++;
		a=a/10;
		b=b/10;
	}
	if(cnt==1)
		return true;
	return false;
}


void buildgraph()
{
	for(int i=1000;i<=9999;i++)
	{
		if(isprime(i))
			prime.push_back(i);
	}
	for(int i=0;i<prime.size();i++)
	{
		for(int j=i+1;j<prime.size();j++)
		{
			int a=prime[i];
			int b=prime[j];

			if(isvalid(a,b))
				arr[a].push_back(b) ,arr[b].push_back(a);
		}
	}
}

void bfs(int a)
{
	queue<int> q;
	q.push(a);
	visit[a]=true;
	dist[a]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto e:arr[node])
		{
			if(visit[e]==false)
			{
				visit[e]=true;
				dist[e]=dist[node]+1;
				q.push(e);
			}
		}
	}
}
int main()
{
	int t,a,b;
	cin>>t;
	buildgraph();
	while(t--)
	{
		cin>>a>>b;

		for(int i=1000;i<=9999;i++) dist[i]=-1,visit[i]=0;
		bfs(a);

		if(dist[b]==-1)
			cout<<"Impossible"<<endl;
		else
			cout<<dist[b]<<endl;
	}
}