#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN=100005;
int dp[maxN][2];
ll binery_string(int n,int ele)
{
	if(n==1 && ele==1)
	return 1;
	if(n==1 && ele==0)
	return 2;
	if(dp[n][ele]!=0)
	return dp[n][ele];
	ll ans;
	if(ele==1)
	ans=binery_string(n-1,0);
	else
	ans=binery_string(n-1,0)+binery_string(n-1,1);
	return dp[n][ele]=ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll ans=binery_string(n,0);
		cout<<ans<<endl;
	}
}
