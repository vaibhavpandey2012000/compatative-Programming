#include<bits/stdc++.h>
using namespace std;
bool isvalid(int x,int y,int N,int M)
{
	if(x<0||x>N-1||y<0||y>M-1)
	return false;
	if(vis[x][y]==1)
	return false;
	return true;
}
int dx[]={-1,0,+1,0};
int dy[]={0,+1,0,-1};
void dfs(int x,int y,int vis[50][50],int m,int n)
{
	vis[x][y]=1;
	cout<<x<<" "<<y<<endl;
	for(int i=0;i<4;i++)
	if(isvalid(x+dx[i],y+dy[i],m,n))
	dfs(x+dx[i],y+dy[i]);
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int m,n;
		cin>>m>>n;
		char ch[m][m];
		vector<pair<int,int> > GG,BB;
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(ch[i][j]=='G')
			GG.push_pack({i,j});
			if(ch[i][j]=='B')
			BB.push_back({i,j});
		}
		for(int i=0;i<GG.size();i++)
		{
			int vis[m][n]={0};
			dfs(x,y,vis[50][50],m,n);
			
		}
		
		
	}
}
