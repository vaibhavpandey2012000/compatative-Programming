#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define rep(i) for(int i=0;i<2;i++)
ll mat[2][2],I[2][2];

void multiply(ll I[2][2],ll mat[2][2])
{
	ll ans[2][2];
	rep(i){
		rep(j){
			ans[i][j]=0;
			rep(k)
			ans[i][j]=(ans[i][j]+(I[i][k]*mat[k][j])%MOD)%MOD;
		}
	}
	rep(i)rep(j)I[i][j]=(ans[i][j]%MOD);
}

void power(ll mat[2][2],ll n)
{
	I[0][0]=1,I[0][1]=0;
	I[1][0]=0,I[1][1]=1;
	
	while(n)
	{
		if(n&1)	multiply(I,mat),n--;
		else multiply(mat,mat) ,n=(n>>1);
	}
	rep(i) rep(j) mat[i][j]=I[i][j];
}
int main()
{
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
			power(mat,n);
			cout<<((a*mat[0][0])%MOD+(b*mat[1][0])%MOD)%MOD<<endl;
			
			rep(i)rep(j) mat[i][j]=0,I[i][j]=0;
		}
		
	}
}

