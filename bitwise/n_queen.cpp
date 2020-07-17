#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0,DONE;
int bord[100][100]={0};
int getposition(int n)
{
	int ans=0;
	while(n>0)
	{
		ans++;
		n=(n>>1);
	}
	return ans-1;
}
void solve(int rowmask,int ld,int rd,int row)
{
	if(rowmask==DONE)
	{
		ans++;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<bord[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	int safe=DONE & (~(rowmask|ld|rd));
	while(safe)
	{
		int p= safe & (-safe);
		int col=getposition(p);
		bord[row][col]=1;
		safe=safe-p;
		solve(rowmask|p,(ld|p)<<1,(rd|p)>>1, row+1);
		bord[row][col]=0;
	}
}
int main()
{
	cin>>n;
	DONE=(1<<n)-1;
	solve(0,0,0,0);
	cout<<ans<<endl;
}