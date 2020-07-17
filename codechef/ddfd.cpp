#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define ll long long
ll mat[2][2],I[2][2];

void multiply(ll I[][2],ll mat[][2],ll dim)
{
	ll ans[2][2];
	rep(i,dim)
		rep(j,dim)
		{
			ans[i][j]=0;
			rep(k,dim)
			ans[i][j]=(ans[i][j]+(I[i][k]*mat[k][j])%MOD)%MOD;
		}
	
	rep(i,dim)
		rep(j,dim)
			I[i][j]=ans[i][j];
}
void power(ll mat[][2],ll dim,ll p)
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
		ll a,b,n;
		cin>>a>>b>>n;
		if(n==1) cout<<b<<endl;
		else{
			mat[0][0]=0,mat[0][1]=1;
			mat[1][0]=1,mat[1][1]=1;
			
			power(mat,2,n);
			
			ll rec[2]={1,1};
			
			cout<<a*mat[0][0]+b*mat[1][0]<<endl;
			
			rep(i,2) rep(j,2) mat[i][j]=0,I[i][j]=0;
		}
	}
}
