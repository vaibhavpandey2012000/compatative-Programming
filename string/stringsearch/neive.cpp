#include<bits/stdc++.h>
using namespace std;
void neive(string s,string p)
{
	for(int i=0;i<=s.length()-p.length();i++)
	{
		int j;
		for( j=0;j<p.length();j++)
		{
			if(s[i+j]!=p[j])
			break;
		}
		if(j==p.length())
		{
			cout<<"pattern present at "<<i<<"th position."<<endl;
		}
	}
}
int main()
{
	string s,p;
	cin>>s>>p;
	neive(s,p);	
}