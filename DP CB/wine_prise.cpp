#include<bits/stdc++.h>
using namespace std;
const int maxN=100;
int wine[100][100]={0};
int solve(int *arr,int i,int j,int cnt)
{
	if(i>j)
	return 0;
	if(wine[i][j]!=0)
	return wine[i][j];
	int ans=max(arr[i]*cnt+solve(arr,i+1,j,cnt+1),arr[j]*cnt+solve(arr,i,j-1,cnt+1));
	return wine[i][j]=ans;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int sol=solve(arr,0,n-1,1);
	cout<<sol<<endl;
}