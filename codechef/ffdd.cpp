#include<bits/stdc++.h>
using namespace std;
void multiply(int a[2][2],int b[2][2])
{
	int ans[2][2];
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	{
		ans[i][j]=0;
		for(int k=0;k<2;k++)
		ans[i][j]+=a[i][k]*b[k][j];
	}
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	a[i][j]=ans[i][j];
}
void power(int mat[2][2],int n)
{
	int ans[2][2];
	ans[0][0]=1,ans[0][1]=0;
	ans[1][0]=0,ans[1][1]=1;
	
	while(n)
	{
		if(n&1) multiply(ans,mat),n=n-1;
		else multiply(mat,mat),n=n/2;
	}
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	mat[i][j]=ans[i][j];
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		if(n==1||n==2)
		{
			cout<<"1"<<endl;
			continue;
		}
		int mat[2][2]={{0,1},{1,1}};
		power(mat,n-1);
		cout<<mat[0][0]+mat[1][0]<<endl;
	}
}
