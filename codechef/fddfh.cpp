#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int lps(string ss,int s,int e)
{
	if(s>e) return 0;
	if(s==e) return dp[s][e]=1;
	if(dp[s][e]) return dp[s][e];
	if(ss[s]==ss[e])
	{
		int len=e-s-1;
		if(len==lps(ss,s+1,e-1))
		{
			return dp[s][e]=2+len;
		}
	}
	return dp[s][e]=max(lps(ss,s+1,e),lps(ss,s,e-1));
}
int lpsb(string ss,int n)
{
	if(ss=="") return 0;
	bool arr[n][n];
	for(int i=0;i<n;i++)
	arr[i][i]=1;
	int maxlps=1;
	for(int i=n-2;i>=0;i--)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ss[i]==ss[j])
			{
				if(arr[i+1][j-1]||j-i==1){
					arr[i][j]=1;
					maxlps=max(maxlps,j-i+1);
				}	
			}
		}
	}
	return maxlps;
}

int main()
{
	string s;
	cin>>s;
	int ans=lps(s,0,s.length()-1);
	int ans2=lpsb(s,s.length());
	//visuvilasation
	/*
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;	
	}
	*/
	cout<<ans<<"  "<<ans2<<endl;
}
