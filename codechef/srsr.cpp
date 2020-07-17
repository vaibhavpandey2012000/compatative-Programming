#include<bits/stdc++.h>
using namespace std;
bool isvalid(int x,int y,int n,int m,bool vis[50][50],char ch[50][50])
{
	if(x<0||x>n-1||y<0||y>m-1)
	return false;
	if(vis[x][y]==1 || ch[x][y]=='#')
	return false;
	else 
	return true;
}
void dfs(int x,int y,int n,int m,bool vis[50][50],char ch[50][50])
{
	vis[x][y]=1;
	if(isvalid(x-1,y,n,m,vis,ch))
	dfs(x-1,y,n,m,vis,ch);
	if(isvalid(x+1,y,n,m,vis,ch))
	dfs(x+1,y,n,m,vis,ch);
	if(isvalid(x,y-1,n,m,vis,ch))
	dfs(x,y-1,n,m,vis,ch);
	if(isvalid(x,y+1,n,m,vis,ch))
	dfs(x,y+1,n,m,vis,ch);
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		char ch[50][50];
		vector<pair<int,int> > GG,BB;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>ch[i][j];
			if(ch[i][j]=='G')
			GG.push_back({i,j});
			if(ch[i][j]=='B')
			BB.push_back({i,j});
		}
		if(GG.size()==0)
		{
			cout<<"Yes"<<endl;
			continue;
		}
		bool visit[50][50];
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		visit[i][j]=false;
		for(int i=0;i<BB.size();i++)
		{
			int x=BB[i].first,y=BB[i].second;
			if(x-1>=0) ch[x-1][y]='#';
			if(x+1<n) ch[x+1][y]='#';
			if(y-1>=0) ch[x][y-1]='#';
			if(y+1<m) ch[x][y+1]='#';
		}
		if(ch[n-1][m-1]=='#')
		{
			cout<<"No"<<endl;
			continue;
		}
		dfs(n-1,m-1,n,m,visit,ch);
		int ff=1;
		for(int i=0;i<GG.size();i++)
		{
			int x=GG[i].first,y=GG[i].second;
			if(visit[x][y]!=1)
			{
				cout<<"No"<<endl;
				ff=0;
				break;
			}
		}
		if(ff)cout<<"Yes"<<endl;
	}
}
