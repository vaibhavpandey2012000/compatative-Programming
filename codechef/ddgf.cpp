#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[31]={0};
ll hand_sake(int n)
{
	if(dp[n]!=0) return dp[n];
	else{
		dp[n]=hand_sake(n-1)+(n-1)*hand_sake(n-2);
	}
	return dp[n];
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		dp[1]=1,dp[2]=2;
		ll ans=hand_sake(n);
		cout<<ans<<endl;		
	}
}
