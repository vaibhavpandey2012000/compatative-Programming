#include<bits/stdc++.h>
using namespace std;
int solve(int *w,int *p,int c,int n)
{
	if(n==0  || c<=0)
	return 0;
	int arr[c+1][n];
	for(int j=0;j<=c;j++)
	{
		if(w[0]<=j)
		arr[0][j]=p[0];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=c;j++)
		{
			int ip=0;
			if(w[i]<=j)
			{
				ip=p[i]+arr[i-1][j-w[i]];
			}
			arr[i][j]=max(arr[i-1][j],ip);
		}
	}
	return arr[n-1][c];
}
int main()
{
	int n;
	cin>>n;
	int w[n],p[n];
	for(int i=0;i<n;i++) cin>>w[i];
	for(int i=0;i<n;i++) cin>>p[i];
	int cap=8;
	int ans=solve(w,p,cap,n);
	cout<<ans<<endl;
}
