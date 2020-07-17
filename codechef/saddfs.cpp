#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
int arr[maxN];
int minstap_bottomup(int n)
{
	int dp[n+1];
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		int a=INT_MAX,b=INT_MAX,c;
		if(i%2==0)
		a=dp[i/2];
		if(i%3==0)
		b=dp[i/3];
		c=dp[i-1];
		dp[i]=min(a,min(b,c))+1;
	}
	return dp[n];
}
int minstap_topup(int n)
{
	if(n==1)
	return 0;
	if(arr[n]!=0)
	return arr[n];
	int a=INT_MAX,b=INT_MAX,c;
	if(n%2==0)
	a=minstap_topup(n/2);
	if(n%3==0)
	b=minstap_topup(n/3);
	c=minstap_topup(n-1);
	return arr[n]=(min(a,min(b,c))+1);
}
int main()
{
	int n;
	cin>>n;
	cout<<minstap_bottomup(n)<<endl;
	cout<<minstap_topup(n)<<endl;
}
