#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int>v;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1')
		v.push_back(i);
	}
	if(v.size()==0)
	{
		cout<<(n+k)/(k+1)<<endl;
		continue;
	}
	int ans=0;
	ans+=(v[0]-k-1)/(k+1);
	for(int i=1;i<v.size();i++)
	{
		ans+=(v[i]-v[i-1]-1)/(k+1);
	}
	ans+=(n-v[v.size()-1]+1)/(k+1);
	cout<<ans<<endl;
	}
}
