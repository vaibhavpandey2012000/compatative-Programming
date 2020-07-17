#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n+2],dp[n+2]={0};
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	for(int i=2;i<=n;i++)
	if(arr[i]!=1)
	dp[i]=min(dp[i-1],dp[i-2])+1;
	else
	dp[i]=INT_MAX;
	for(int i=1;i<=n;i++)
	cout<<dp[i]<<" ";
	cout<<dp[n]<<endl;
	
}
