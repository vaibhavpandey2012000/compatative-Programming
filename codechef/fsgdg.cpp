#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<vector<long> >  mul(vector<vector<long> > A,vector<vector<long> > B)
{
	vector<vector<long> > ans={{1,0},{0,1}};
	ans[0][0]=(A[0][0]*B[0][0]+A[0][1]*B[1][0])%MOD;
	ans[0][1]=(A[0][0]*B[0][1]+A[0][1]*B[1][1])%MOD;
	ans[1][0]=(A[1][0]*B[0][0]+A[1][1]*B[1][0])%MOD;
	ans[1][1]=(A[1][0]*B[0][1]+A[1][1]*B[1][1])%MOD;
	return ans;
}
vector<vector<long> > fastpow(vector<vector<long> > v,long n)
{
	if(n==0)
	{
		vector<vector<long> > ans={{1,0},{0,1}};
		return ans;
	}
	vector<vector<long> > a1=fastpow(v,n/2);
		a1=mul(a1,a1);
		if(n&1)
		return mul(a1,v);
		return a1;
	
}
long expo(long a,long b,long n)
{
	if(n==1) return b%MOD;
	vector<vector<long> > v={{a,b},{1,0}};
	vector<vector<long> > ans=fastpow(v,n);
	return ans[0][0];
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long a,b,n;
		cin>>a>>b>>n;
		long ans=expo(a,b,n);
		cout<<ans<<endl;
	}
}
