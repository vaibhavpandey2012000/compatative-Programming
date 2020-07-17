#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int mat[2][2],I[2][2];

void multiply(int I[][2],int mat[][2],int dim)
{
	int ans[2][2];
	rep(i,dim)
		rep(j,dim)
		{
			ans[i][j]=0;
			rep(k,dim)
			ans[i][j]+=(I[i][k]*mat[k][j]);
		}
	
	rep(i,dim)
		rep(j,dim)
			I[i][j]=ans[i][j];
}
void power(int mat[][2],int dim,int p)
{
	rep(i,dim) rep(j,dim)
	if(i==j) I[i][j]=1;
		
	while(p)
	{
		if(p&1) multiply(I,mat,dim) ,p--;
		else multiply(mat,mat,dim) ,p=(p>>1);
	}
	
	rep(i,dim)
		rep(j,dim)
			mat[i][j]=I[i][j];
}

int main(){
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		if(n==0||n==1) cout<<"n"<<endl;
		else{
			mat[0][0]=0,mat[0][1]=1;
			mat[1][0]=1,mat[1][1]=1;
			
			power(mat,2,n-1);
			
			int rec[2]={1,1};
			
			cout<<mat[0][0]+mat[1][0]<<endl;
			
			rep(i,2) rep(j,2) mat[i][j]=0,I[i][j]=0;
		}
	}
}