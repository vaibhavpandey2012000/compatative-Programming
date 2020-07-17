#include<bits/stdc++.h>
using namespace std;
string chack(string & s1,string & s2)
{
	if(s2.length()>s2.length())
	{
		string p1="No string";
		return p1;
	}
	int n_s[256],n_p[256],si=-1,ml=INT_MAX;
	for(int i=0;i<s2.length();i++)
	{
		n_p[s2[i]]++;
	}
	int c=0,s=0;
	for(int i=0;i<s1.length();i++)
	{
		n_s[s1[i]]++;
		if(n_p[s1[i]] !=0 && n_p[s1[i]]<=n_s[s1[i]])
		{
			c++;
		}
		if(c==s2.length())
		{
			while((n_s[s1[s]]>n_p[s1[s]]) || n_p[s1[s]]==0)
			{
				if(n_s[s1[s]]>n_p[s1[s]])
					n_s[s1[s]]--;
				s++;
			}
			int lw=i-s+1;
			if(ml>lw)
			{
				ml=lw;
				si=s;
			}
		}
	}
	if(si==-1)
	{
		return "No string";
	}
	return s1.substr(si,ml);
}
int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	string ans=chack(s1,s2);
	cout<<ans<<endl;
}