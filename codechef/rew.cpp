#include<bits/stdc++.h>
using namespace std;
int LSS(int *arr,int n)
{
	unordered_map<int,int>mp;
	mp[0]=0;
	int pre=0;
	int len=0;
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		if(mp.find(pre)!=mp.end())
		{
			len=max(len,i-mp[pre]);
		}
		else
		{
			mp[pre]=i;
		}
	}
	return len;
}
int LS(int *arr,int n)
{
	unordered_map<int,int>mp;
	int pre=0;
	int len=0;
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		if(len==0 && arr[i]==0) len=1;
		if(pre==0) len=max(len,i+1);
		if(mp.find(pre)!=mp.end())
		{
			len=max(len,i-mp[pre]);
		}
		else
		{
			mp[pre]=i;
		}
	}
	return len;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans=LS(arr,n);
	cout<<ans<<endl;
}
