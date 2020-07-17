#include<bits/stdc++.h>
using namespace std;
int fxn(string s1,string s2)
{
	if(s1==s2)
	{
		return 1;
	}
	if(s1.length()%2==1 || s2.length()%2==1)
	{
		return 0;
	}
	string s11=s1.substr(0,s1.length()/2),s12=s1.substr(s1.length()/2,s1.length());
	string s21=s2.substr(0,s2.length()/2),s22=s2.substr(s2.length()/2,s2.length());
	return (((fxn(s11,s21)&fxn(s12,s22))|(fxn(s11,s22)|fxn(s12,s21))));
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string a,b;
		cin>>a>>b;
		int val= fxn(a,b);
		val==1? cout<<"YES"<<endl:cout<<"NO"<<endl;
	}
}