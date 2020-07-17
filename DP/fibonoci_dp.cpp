#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000000+7
using namespace std;
int dp[100000];
ll fibrec(int n)
{
	if(n==0||n==1) return n;
	ll ff=fibrec(n-1);
	ll ss=fibrec(n-2);
	return ff+ss;
}

ll fibtop(int n)
{
	if(n==0||n==1) return n;
	if(dp[n]!=0) return dp[n];
	ll ff=fibtop(n-1);
	ll ss=fibtop(n-2);
	return dp[n]=(ff+ss)%MOD;
}

ll fibbot(int n)
{
	int arr[n+1];
	arr[0]=0,arr[1]=1;
	for(int i=2;i<=n;i++)
	{
		arr[i]=(arr[i-1]+arr[i-2])%MOD;
	}
	return arr[n];
}
int main()
{
	int n;
	cin>>n;
//	ll ans0=fibrec(n);// limit n=40
	ll ans1=fibtop(n);// limit n=100000
	ll ans2=fibbot(n);
	cout/*<<ans0<<" "*/<<ans1<<" "<<ans2<<endl;
}