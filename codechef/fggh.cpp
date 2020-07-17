#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int mat[60][60];
		int n,p;
		cin>>n>>p;
		int init=p/100;
		for(int i=0;i<init;i++)
		{
			if(i&1)
			mat[i][i]=1;
			else
			mat[n-i-1][n-i-1]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	}
}
