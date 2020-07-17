#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > multiply(vector<vector<int> >A,vector<vector<int> >B,int n)
{
	vector<vector<int> >ans(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			ans[i][j]=0;
			for(int k=0;k<n;k++)
			ans[i][j]+=A[i][k]*B[k][j];
		}
	}
	return ans;
}

vector<vector<int> >power(vector<vector<int> >v,int n,int p)
{
	//cout<<n<<" "<<p<<endl;
	vector<vector<int> >ans(n,vector<int>(n));
	for(int i=0;i<n;i++) ans[i][i]=1;
	while(p)
	{
		if(p&1) p--,ans=multiply(v,ans,n);
		else p=p/2 ,v=multiply(v,v,n);
	}
	return ans;
}

int main()
{
	int n,p;
	cin>>n>>p;
	vector<vector<int> >v(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cin>>v[i][j];
	}
	v=power(v,n,p);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<v[i][j]<<" ";
		cout<<endl;
	}
	
}