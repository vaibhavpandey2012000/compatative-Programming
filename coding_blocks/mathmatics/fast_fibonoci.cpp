#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;
vector<vector<ll> > mul(vector<vector<ll> > A,vector<vector<ll> > B)
{
	vector<vector<ll> > ans{{0,0},{0,0}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				ans[i][j]=(ans[i][j]+((A[i][k] % MOD)*(B[k][j] % MOD))% MOD)% MOD;
			}
		}
	}
	return ans;
}
vector<vector<ll> > power(vector<vector<ll> > v,ll n)
{
	vector<vector<ll> >ans{{1,0},{0,1}};
	if(n==1)
	{
		return v;
	}
	ans=power(v,n/2);
	ans=mul(ans,ans);
	if(n&1)
	ans= mul(ans,v);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
	vector<vector<ll> > v{{0,1},{1,1}};
	ll n;
	cin>>n;
	vector<vector<ll> >ans=power(v,n);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<2;j++)
//		{
//			cout<<ans[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<ans[0][1]<<endl;
	}
}