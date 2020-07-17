#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll ct[101]={0};
int main()
{
	int n;
	cin>>n;
	if(n>=130)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	set<ll>s;
	vector<ll>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<n;i++)
	{
		if(s.find(v[i-1]^v[i])!=s.end())
		{
			cout<<"YES"<<endl;
			return 0;
		}
		s.insert(v[i-1]^v[i]);
	}
	cout<<"NO"<<endl;
}