#include<bits/stdc++.h>
using namespace std;
char grid[1001][1001];
int vis[1001][1001],dis[1001][1001];
int n,m;
vector<pair<int,int> >vp;

bool isvaild(int x,int y)
{
	if(x<1||x>n||y<1||y>m)
	return false;
	if(vis[x][y]==1 || grid[x][y]=='#')
	return false;
	return true;
}

int dx[]={-1,0,+1,0};
int dy[]={0,+1,0,-1};

void bfs(int x,int y)
{
	queue<pair<int,int> >q;
	q.push({x,y});
	vis[x][y]=1;
	dis[x][y]=0;
	while(!q.empty())
	{
		int nodex=q.front().first;
		int nodey=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(isvaild(nodex+dx[i],nodey+dy[i]))
			{
				int newx=nodex+dx[i];
				int newy=nodey+dy[i];
				dis[newx][newy]=dis[nodex][nodey]+1;
				vis[newx][newy]=1;
				q.push({newx,newy});
			}
		}
	}
}


int main()
{
	int x,y,sx,sy;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>grid[i][j];
		if(grid[i][j]=='A')
		x=i,y=j;
		if(grid[i][j]=='B')
		sx=i,sy=j;
		dis[i][j]=-1;	
	}
	bfs(x,y);
	if(dis[sx][sy]==0)
	cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<dis[sx][sy]<<endl;
		string s;
		int dd=dis[sx][sy];
		while(dd!=0)
		{
			if(dis[sx-1][sy]==dd-1)
			{
			//	cout<<"D";
				s+='D';
				dd--;
				sx=sx-1;
				sy=sy;
				continue;
			}
			if(dis[sx][sy+1]==dd-1)
			{
			//	cout<<"L";
				s+='L';
				dd--;
				sx=sx;
				sy=sy+1;
				continue;
			}
			if(dis[sx+1][sy]==dd-1)
			{
			//	cout<<"U";
				s+='U';
				dd--;
				sx=sx+1;
				sy=sy;
				continue;
			}
			if(dis[sx][sy-1]==dd-1)
			{
			//	cout<<"R";
				s+='R';
				dd--;
				sx=sx;
				sy=sy-1;
				continue;
			}
		}
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
	
}
