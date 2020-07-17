#include<bits/stdc++.h>
using namespace std;
int dp[5000][5000];
int solve(vector<int> &v,int l,int r)
{
	if(l==r) return 0;
	if(l==r-1 && v[l]!=v[r]) {
		return 1;
	}
	if(dp[l][r]) return dp[l][r];
	else if(v[l]==v[r])
	{
		dp[l][r]=1+solve(v,l+1,r-1);
	}
	else if(dp[l]!=dp[r]){
		int v1=solve(v,l+1,r)+1;
		int v2=solve(v,l,r-1)+1;
		dp[l][r]=min(v1,v2);
	}
	return dp[l][r];
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<int>v;
	v.push_back(arr[0]);
	for(int i=1;i<n;i++)
	if(arr[i]!=arr[i-1])
	v.push_back(arr[i]);
	int ans=solve(v,0,v.size()-1);
	cout<<ans<<endl;
}
