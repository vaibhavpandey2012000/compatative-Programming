#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int lps(string ss,int s,int e)
{
	if(s>e) return 0;
	if(s==e) return 1;
	if(dp[s][e]!=0) return dp[s][e];
	if(ss[s]==ss[e]) return dp[s][e]=2+lps(ss,s+1,e-1);
	return dp[s][e]=max(lps(ss,s+1,e),lps(ss,s,e-1));
}
int lps_bottom(string s,int l)
{
	if(l==0) return 0;
	int arr[l][l]={0};
	for(int i=0;i<s.length();i++)
	arr[i][i]=1;
	
	for(int i=l-2;i>=0;i--)
	{
		for(int j=i+1;j<l;j++)
		{
			if(s[i]==s[j]) arr[i][j]=2+arr[i+1][j-1];
			else
			arr[i][j]=max(arr[i+1][j],arr[i][j-1]);
		}
	}
	return arr[0][l-1];
}
int main()
{
	string s;
	cin>>s;
	int len=lps(s,0,s.length()-1);
	int len2=lps_bottom(s,s.length());
	cout<<len<<" "<<len2<<endl;
}
