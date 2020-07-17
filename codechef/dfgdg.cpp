#include<bits/stdc++.h>
using namespace std;
int vis[50][50];
int N,M;
bool isvalid(int x,int y)
{
	if(x<1||x>N||y<1||y>M)
	return false;
	if(vis[x][y]==1)
	return false;
	return true;
}
//void dfs(int x,int y)
//{
//	vis[x][y]=1;
//	cout<<x<<" "<<y<<endl;
//	if(isvalid(x-1,y))
//	dfs(x-1,y);
//	if(isvalid(x,y+1))
//	dfs(x,y+1);
//	if(isvalid(x+1,y))
//	dfs(x+1,y);
//	if(isvalid(x,y-1))
//	dfs(x,y-1);
//}
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
	cin>>N>>M;
	int x,y;
	cin>>x>>y;
	dfs(x,y);
}
