#include<bits/stdc++.h>
using namespace std;
long dp[250][100]={0};
#define MOD 1000000007
 long fxn(int n,int k,int *arr)
{
    if(n==0) return 1;
    else if(n<0 || k<=0) return 0;
    if(dp[n][k]!=0) return dp[n][k];
    int ans=0;
    if(n-arr[k]>=0)
    ans+=fxn(n-arr[k],k,arr);
    ans+=fxn(n,k-1,arr);
    return dp[n][k]=ans;
}
int main()
{
	memset(dp,0,sizeof(dp));
    int n,k;
    cin>>n>>k;
    int arr[k+1];
    for(int i=1;i<=k;i++)
    cin>>arr[i];
    long sol=fxn(n,k,arr);
    cout<<sol<<endl;
}
