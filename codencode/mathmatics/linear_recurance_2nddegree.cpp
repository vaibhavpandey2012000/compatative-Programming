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
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n=2,a,b,p;
		cin>>a>>b>>p;
		if(p==1) {
			cout<<a<<endl ;continue;
		}
		p=p-1;
		vector<vector<int> >v(n,vector<int>(n));
		v[0][0]=0,v[1][0]=1,v[1][1]=1,v[0][1]=1;
		v=power(v,n,p);
	
		cout<<a*v[0][0]+b*v[1][0]<<endl;	
	}	
}