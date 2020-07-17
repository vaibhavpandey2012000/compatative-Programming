#include<bits/stdc++.h>
using namespace std;
int ans=0;
bool issafe(char bord[10][10],int i,int j,int n)
{
	for(int row=0;row<i;row++)
	if(bord[row][j]=='Q') return false;
	int x=i,y=j;
	while(x>=0 && y>=0){
		if(bord[x][y]=='Q') return false;
		x--;
		y--;
	}
	x=i,y=j;
	while(x>=0 && y<n)
	{
		if(bord[x][y]=='Q') return false;
		x--,y++;
	}
	return true;
}
bool solveNQueen(char bord[10][10],int i,int n)
{
	if(i==n)
	{
		ans++;
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<n;j++)
//			if(bord[i][j]=='Q') cout<<"Q";
//			else cout<<".";
//			cout<<endl;
//		}
//		cout<<endl;
		return false;
	}
	//recursive
	for(int j=0;j<n;j++)
	{
		if(bord[i][j]=='*') continue;
		if(issafe(bord,i,j,n))
		{
			bord[i][j]='Q';
			bool nextq=solveNQueen(bord,i+1,n);
			if(nextq==true)
			return true;
			bord[i][j]='.';
		}
	}
	return false;
}
int main()
{
	int n=8;
	//cin>>n;
	char bord[10][10];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>bord[i][j];
	solveNQueen(bord,0,n);
	cout<<ans<<endl;
}
