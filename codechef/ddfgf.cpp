#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100005];
ll cnt_subseq(string s)
{
	int sm=1;
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(s[i]-'0'>s[j]-'0')
			dp[i]+=dp[j];
		}
		sm+=dp[i];
	}
//	for(int i=0;i<s.length();i++)
//	cout<<dp[i]<<" ";
//	cout<<endl;
	return sm;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++)
		dp[i]=1;
		ll ans=cnt_subseq(s);
		cout<<ans<<endl;
	}
}
