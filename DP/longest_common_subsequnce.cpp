#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int longest_common_subseq(string s1,string s2,int l1,int l2)
{
	if(l1==0 || l2==0) return 0;
	if(dp[l1][l2]!=0) return dp[l1][l2];
	if(s1[l1-1]==s2[l2-1])
	return dp[l1][l2]=(1+longest_common_subseq(s1,s2,l1-1,l2-1));
	else
	return dp[l1][l2]=max(longest_common_subseq(s1,s2,l1-1,l2),longest_common_subseq(s1,s2,l1,l2-1));
}
int bottomup(string s1,string s2,int l1,int l2)
{
	if(l1==0 || l2==0) return 0;
	dp[l1+1][l2+1]={0};
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1]) dp[i][j]=(1+dp[i-1][j-1]);
			else
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[l1][l2];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int ans=longest_common_subseq(s1,s2,s1.length(),s2.length());
	int ans1=bottomup(s1,s2,s1.length(),s2.length());
	cout<<ans<<" "<<ans1<<endl;
}