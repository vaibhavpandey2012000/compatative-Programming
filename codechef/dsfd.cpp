#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int wine(int i,int j,int *arr,int year)
{
	if(i>j)
	return 0;
	if(dp[i][j]!=0)
	return dp[i][j];
	else{
		int s1=arr[i]*year+wine(i+1,j,arr,year+1);
		int s2=arr[j]*year+wine(i,j-1,arr,year+1);
		return dp[i][j]=max(s1,s2);		
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<wine(0,n-1,arr,1)<<endl;
}
