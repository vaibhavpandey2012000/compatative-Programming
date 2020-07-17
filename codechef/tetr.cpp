#include<bits/stdc++.h>
using namespace std;
char grid[1000][1000];
int vis[1000][1000];
int n,m;

bool isvalid(int x,int y)
{
	if(x<1||x>n||y<1||y>m)
	return false;
	if(vis[x][y]==1 || grid[x][y]=='#')
	return false;
	if(grid[x][y]=='.')
	return true;
}

int dx[]={-1,0,+1,0};
int dy[]={0,+1,0,-1};
void dfs(int x,int y)
{
	vis[x][y]=1;
	//cout<<x<<" "<<y<<endl;
	for(int i=0;i<4;i++)
	if(isvalid(x+dx[i],y+dy[i]))
	dfs(x+dx[i],y+dy[i]);
}

int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>grid[i][j];
	
	int cnt=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(grid[i][j]=='.' && vis[i][j]==0)
	{
		cnt++;
		dfs(i,j);
	//	cout<<endl;
	}
	
	cout<<cnt<<endl;
}
