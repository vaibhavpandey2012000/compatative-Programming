#include<bits/stdc++.h>
using namespace std;
bool dp[1005][1005]={0};
void pre(string s)
{
	int len=s.length();
	for(int j=1;j<=len;j++)
	{
		for(int i=0;i<=len-j;i++)
		{
			if(j<=2)
			{
				if(s[i]==s[i+j-1])
				dp[i][i+j-1]=true;
			}
			else if(s[i]==s[i+j-1])
			{
				dp[i][i+j-1]=dp[i+1][i+j-2];
			}
		}
	}
}
int main()
{
	int l;
	cin>>l;
	string s;
	cin>>s;
	pre(s);
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<l;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		if(dp[l-1][r-1])
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
}
