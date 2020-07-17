#include<bits/stdc++.h>
//#include <boost/algorithm/string.hpp> 
using namespace std;
bool suffix(string & str,string & gstr)
{
	if(str.length()>gstr.length())
	{
		return false;
	}
	int n1=str.length(),n2=gstr.length();
	for(int i=0;i<str.length();i++)
	{
		if(str[n1-i-1]!=gstr[n2-i-1])
			return false;
	}
	return true;
}


int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	bool issuffix=suffix(s1,s2);
	if(issuffix)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}

}