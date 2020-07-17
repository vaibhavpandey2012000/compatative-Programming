#include<bits/stdc++.h>
using namespace std;
int subarryK(int *arr,int n,int k)
{
	int len=0;
	int pre=0;
	unordered_map<int,int> mp;
	mp[0]=0;
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		if(mp.find(pre-k) != mp.end())
		{
			len=max(len,i-mp[pre-k]);
		}
		else{
			mp[pre]=i;
		}
	}
	return len;
}
int sk(int *arr,int n,int k)
{
	unordered_map<int,int>mp;
	int pre=0;
	int len=0;
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		if(pre==k) len=max(len,i+1);
		if(mp.find(pre-k)!=mp.end())
		{
			len=max(len,i-mp[pre-k]);
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
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int &i:arr)
	cin>>i;
	int ans= subarryK(arr,n,k);
	cout<<ans<<endl;
}