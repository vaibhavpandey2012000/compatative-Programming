#include<bits/stdc++.h>
using namespace std;
const int maxN=101;
int mat[maxN][maxN][maxN];
void update(int x,int y,int z,int w,int n)
{
	x++,y++,z++;
	for(int i=x;i<=n;i+=(i&(-i)))
	{
		for(int j=0;j<=n;j+=(j&(-j)))
		{
			for(int k=0;k<=n;k+=(k&(-k)))
			{
				a[i][j][k]+=w;
			}
		}
	}
}
int quary(int x1,int y1,int z1,int x2,int y2,int z2)
{
	
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		memset(mat,0,sizeof(mat));
		int n,m;
		cin>>n>>m;
		while(m--)
		{
			string s;
			cin>>s;
			if(s==UPDATE)
			{
				int x,y,z,w;
				update(x,y,z,w-mat[x][y][z],n);
				mat[x][y][z]=w;
			}
			else
			{
				int x1,y1,z1,x2,y2,z2;
				int ans=quary(x1,y1,z1,x2,y2,z2);
				cout<<ans<<endl;
			}
		}
	}
}