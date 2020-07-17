#include<bits/stdc++.h>
using namespace std;
void solve(int s,int e,string ss)
{
	if(s==0 && e!=0)
	{
		while(e--)
		ss+=')';
		cout<<ss<<endl;
		return;
	}
	else if(s==e && s>0)
	{
		ss+='(';
		solve(s-1,e,ss);
	}
	else if(s<e)
	{
		string pp=ss+'(';
		solve(s-1,e,pp);
		string aa=ss+')';
		solve(s,e-1,aa);
	}
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		string s="";
		solve(n,n,s);
	}
}
