#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[100][2]={0};
ll count_Bstring(int n,int ld)
{
	if(n==1&&ld==0){
		return 2;
	}
	if(n==1&&ld==1){
		return 1;
	}
	if(dp[n][ld]!=0){
			return dp[n][ld];
	}
	ll ans;
	if(ld)
		ans=count_Bstring(n-1,0);
	else
		ans=count_Bstring(n-1,0)+count_Bstring(n-1,1);
	return dp[n][ld]=ans;
	
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll ans=count_Bstring(n,0);
		cout<<ans<<endl;
	}
}
