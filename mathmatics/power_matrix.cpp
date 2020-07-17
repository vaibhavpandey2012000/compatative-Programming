#include<bits/stdc++.h>
using namespace std;
void mul(int a[][2],int b[][2])
{
	int ans[2][2]={0,0,0,0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				ans[i][k]+=(a[i][j]*b[j][k]);
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j]=ans[i][j];
		}
	}

}
void power(int n,int mat[][2])
{
	int aa[2][2]={1,0,0,1};
	while(n>0)
	{
		if(n&1)
			mul(aa,mat);
		mul(mat,mat);
		n=(n>>1);
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			mat[i][j]=aa[i][j];
		}
	}
}
int main()
{
	int mat[2][2]={0,1,1,1};
	int n;
	cin>>n;
	power(n,mat);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}