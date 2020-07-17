#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	cin>>n;
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	int k,mx=INT_MAX;
	cin>>k;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(it->second==k)
		{
			int x=it->first;
			mx=min(mx,x);
		}
	}
	cout<<mx<<endl;
}
