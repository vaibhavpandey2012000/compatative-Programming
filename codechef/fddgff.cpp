#include<bits/stdc++.h>
using namespace std;
const int maxN=10005;
int A[maxN],B[maxN],C[maxN];
vector<int>arr[maxN];
bool visit[maxN];
int dist[maxN];
int cnt=0;
void DFS(int src)
{
	cnt++;
	visit[src]=1;
	//cout<<src<<",";
	for(auto e:arr[src])
	{
		if(visit[e]==0)
		DFS(e);
	}
}
void DFS1(int src)
{
	cnt++;
	visit[src]=1;
	cout<<src<<" ";
	for(auto e:arr[src])
	{
		if(visit[e]==0)
		DFS1(e);
	}
}
int main()
{
	int t,v,e,a,b;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		cin>>v>>e;
		int mx=-1;
		for(int i=1;i<=v;i++) cin>>A[i];
		for(int i=1;i<=v;i++) cin>>B[i];
		for(int i=1;i<=v;i++) C[i]=A[i]/B[i], mx=max(C[i],mx);
		
		for(int i=0;i<=v;i++) arr[i].clear() , visit[i]=0 , dist[i]=0;

		while(e--) {
			cin>>a>>b ;
			if(C[a-1]==mx && C[b-1]==mx){
				arr[a].push_back(b) , arr[b].push_back(a);
			}
		}

		int pp=0;
		vector<int>vv;
		for(int i=1;i<=v;i++)
		{
			if(C[i]==mx)
			vv.push_back(i);
		}
		int cn=1,id=vv[0];
		for(int i=0;i<vv.size();i++)
		{
			DFS(vv[i]);
			if(cnt>cn)
			{
				cn=cnt;
				id=vv[i];
			}
			cnt=0;
		}
		for(int i=0;i<=v;i++) visit[i]=false;
		cout<<cnt<<endl;
		DFS1(vv[0]);
	}
}
