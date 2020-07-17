#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fxn(string s)
{
	if(s.length()==1)
	{
		return s[0]-'0';
	}
	ll y=fxn(s.substr(1));
	cout<<y<<endl;
	ll x=s[0]-'0';
	x=x*(pow(10,s.length()-1))+y;
	return x;
}
int main()
{
	string s;
	cin>>s;
	cout<<fxn(s)<<endl;
}