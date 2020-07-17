#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int min_distance(string s1,string s2,int l1,int l2)
{
	if(l1==0) return l2;
	if(l2==0) return l1;
	if(dp[l1][l2]!=0) return dp[l1][l2];
	if(s1[l1-1]==s2[l2-1]) return dp[l1][l2]=min_distance(s1,s2,l1-1,l2-1);
	int p1=min_distance(s1,s2,l1,l2-1);
	int p2=min_distance(s1,s2,l1-1,l2);
	int p3=min_distance(s1,s2,l1-1,l2-1);
	return dp[l1][l2]=(1+min(p1,min(p2,p3)));
}
int chack_string_match(string s1,string s2)
{
	if(s1==s2) return 0;
	return min_distance(s1,s2,s1.length(),s2.length());
}

//bottom up
int bottom_up(string s1,string s2,int l1,int l2)
{
	if(s1==s2)return 0;
	if(l1==0) return l2;
	if(l2==0) return l1;
	int arr[l1+1][l2+1]={0};
	for(int i=0;i<=l2;i++)
	arr[0][i]=i;
	for(int j=0;j<=l1;j++)
	arr[j][0]=j;
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[i-1])
			arr[i][j]=arr[i-1][j-1];
			else
			{
				arr[i][j]=1+min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));
			}
		}
	}
	return arr[l1][l2];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int ans=chack_string_match(s1,s2);
	int ans2=bottom_up(s1,s2,s1.length(),s2.length());
	cout<<ans<<" "<<ans2<<endl;
}
