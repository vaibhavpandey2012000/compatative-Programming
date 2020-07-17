#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll cnt_subsq(string s)
{
	vector<int>ch(256,-1);
	ll dp[s.length()+1];
	dp[0]=1;
	for(int i=1;i<=s.length();i++)
	{
		dp[i]=(2*dp[i-1])%MOD;
		if(ch[s[i-1]]!=-1)
		{
			dp[i]=(dp[i]-dp[ch[s[i-1]]])%MOD;
		}
		ch[s[i-1]]=(i-1);
	}
//	for(int i=0;i<s.length();i++)
//	cout<<dp[i]<<" ";
//	cout<<endl;
	return dp[s.length()];
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		ll ans=cnt_subsq(s);
		cout<<ans<<endl;
	}
}
