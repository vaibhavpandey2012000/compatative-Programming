#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(vector<int> &v)
{
	int dp[200][200];
	memset(dp,0,sizeof(dp));
	int n=v.size()-1;
	for(int i=1;i<n;i++)
	{
		int r=0 ,c=i;
		while(c<n)
		{
			int val=INT_MAX;
			for(int pivet=r;pivet<c;pivet++)
			{
				val=min(val,dp[r][pivet]+dp[pivet+1][c]+v[r]+v[pivet+1]+v[c+1]);
			}
			dp[r][c]=val;
			r++,c++;
		}
	}
	return dp[0][n-1];
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	int ans=solve(v);
	cout<<ans<<endl;
}