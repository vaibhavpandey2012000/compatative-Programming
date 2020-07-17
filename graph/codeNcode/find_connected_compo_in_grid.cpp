#include<bits/stdc++.h>
using namespace std;
int grid[100][100],vis[100][100];
int n,m;

bool isvalid(int x,int y)
{
	if(x<1||x>n||y<1||y>m)
	return false;
	if(vis[x][y]==1 )
	return false;
	if(grid[x][y]==1)
	return true;
}

int dx[]={-1,0,+1,0};
int dy[]={0,+1,0,-1};
void dfs(int x,int y)
{
	vis[x][y]=1;
	cout<<x<<" "<<y<<endl;
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
	if(grid[i][j]==1 && vis[i][j]==0)
	{
		cnt++;
		dfs(i,j);
	}
	
	cout<<cnt<<endl;
}