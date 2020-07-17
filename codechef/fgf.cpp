#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<char,int>mp;
	for(int i=0;i<n;i++)
	{
		mp[s[i]]++;
	}
	for(auto e:mp)
	cout<<e.first<<" "<<e.second<<endl;
}
