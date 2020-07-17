#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
vector<vector<ll> > mul(vector<vector<ll> >A,vector<vector<ll> >B)
{
	vector<vector<ll> >ans={{0,0},{0,0}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			ans[i][j]=(ans[i][j]+((A[i][k]*B[k][j]+MOD)%MOD)+MOD)%MOD;
		}
	}
	return ans;
}
vector<vector<ll> > power(vector<vector<ll> >mat,ll n)
{
	if(n==0)
	{
		vector<vector<ll> > I={{1,0},{0,1}};
		return I;
	}
	vector<vector<ll> > ans=power(mat,n/2);
	ans=mul(ans,ans);
	if(n&1)
	ans=mul(ans,mat);
	return ans;
}
int main()
{
	vector<vector<ll> >mat={{0,1},{1,1}};
	ll n;
	cin>>n;
	if(n==0 || n==1){
		cout<<n<<endl;
		return 0;
	}
	mat=power(mat,n-1);
	cout<<(mat[0][0]+mat[1][0]+MOD)%MOD<<endl;
}
