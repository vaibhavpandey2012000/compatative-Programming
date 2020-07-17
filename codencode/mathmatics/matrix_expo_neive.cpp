#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
const int N=101;
int mat[N][N],I[N][N];

void multiply(int I[][N],int mat[][N],int dim)
{
	int ans[N][N];
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
void power(int mat[][N],int dim,int p)
{
	rep(i,dim) rep(j,dim)
	if(i==j) I[i][j]=1;
	
	rep(i,p)
	multiply(I,mat,dim);

	
	rep(i,dim)
		rep(j,dim)
			mat[i][j]=I[i][j];
}

void print(int mat[][N],int dim)
{
	rep(i,dim){
		rep(j,dim)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}		
}

int main(){
	int t,dim,p;
	cin>>t;
	while(t--)
	{
		cin>>dim>>p;
		rep(i,dim) rep(j,dim) cin>>mat[i][j];
		
		power(mat,dim,p);
		print(mat,dim);
		
		rep(i,dim) rep(j,dim) mat[i][j]=0,I[i][j]=0;
		
	}
}

/*
55
2 1
1 2
2 1
1 2
2 1

2 2
0 1
1 1
1 1
1 2
2 3
0 1
1 1
1 2
2 3

3 3
1 0 4
1 2 2
0 4 4
17 112 116
15 88 100
28 144 160
*/