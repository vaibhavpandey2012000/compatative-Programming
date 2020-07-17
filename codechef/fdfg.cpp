#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	map<int,int>mp;
	vector<int> v(n),ss;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		mp[v[i]]++;
	}
	ss.push_back(v[0]);
	for(int i=1;i<n;i++)
	{
		if(v[i]==v[i-1])
		continue;
		ss.push_back(v[i]);
	}
	sort(ss.begin(),ss.end());
	for(int i=0;i<ss.size()-1;i++)
	{
		if(ss[i]==ss[i+1])
		{
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<1<<endl;
	set<int>s;
	for(auto e:mp)
	{
		s.insert(e.second);
	}
	if(mp.size()==s.size()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
}
