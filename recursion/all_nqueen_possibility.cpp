#include<bits/stdc++.h>
using namespace std;
bool issafe(int bord[10][10],int i,int j,int n)
{
	for(int row =0;row<i;row++)
	{
		if(bord[row][j]==1)
		return false;
	}
	int x=i,y=j;
	while(x>=0 && j>=0)
	{
		if(bord[x][y]==1)
		return false;
		x--;
		y--;
	}
	x=i,y=j;
	while(x>=0 && y<n)
	{
		if(bord[x][y]==1)
		return false;
		x--;
		y++;
	}
	return true;
}
bool solveNQueen(int bord[10][10],int i,int n)
{
	//basecase
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(bord[i][j]==1)
				cout<<"Q ";
				else
				cout<<"- ";
			}
			cout<<endl;
		}
		cout<<endl;
	//	return true;
	}
	//recursive case
	for(int j=0;j<n;j++)
	{
		if(issafe(bord,i,j,n))
		{
			bord[i][j]=1;
			bool nextqueen=solveNQueen(bord,i+1,n);
			if(nextqueen){
				return true;
			}
			bord[i][j]=0;
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int bord[10][10]={0};
	bool p= solveNQueen(bord,0,n);
}