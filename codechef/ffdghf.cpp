#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int h1[n],h2[n];
	vector<int>a(n),b(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		h1[a[i]]=i;
	}
	for(int j=0;j<n;j++)
	{
		cin>>b[j];
		h2[b[j]]=j;
	}
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		mp[h1[i]-h2[i]]++;
	}
	int mx=0;
	for(auto e:mp){
		mx=max(mx,e.second);
		cout<<e.first<<" "<<e.second<<endl;
	}
	cout<<mx<<endl;
	
}
